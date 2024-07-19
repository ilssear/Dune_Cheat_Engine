-- hl_c_gen.lua

-- C code generator (for AA {$C})



local thisClsName = "hl_c_gen"

local Base = require "Class"

-- comment out the next line to allow more debug info output
-- local function dbg(...) end

local function _cctor(C)
  --C.static.instances_mt.__mode = "" -- we don't want GC to collect registered instances
end

local C = Base:Subclass(thisClsName, _cctor)

-- class static store that should survive the lua files reload
local static = C.static
local instances = static.instances


-- load our circular dependencies
-- mark our module as loaded so that we can safely load them without stack overflow
local preload = require("preload".."")
preload.SetModuleResult(thisClsName, C)
-- circular deps (they also mark self as loaded before loading us)
-- NONE YET


require("defines" .. "")
local serpent = require("serpent".."")
local U = require("util".."")
local MR = require("MemRec".."")
local CU = require("c_util".."")
local T = require("hlType".."")
local hl = require("hl".."")

local lfs = require("lfs".."")
--local preload = require("preload".."")

local sep = package.config:sub(1, 1)
local sep2x = sep .. sep

--[[
local _hlcgCache = _G["_hlcgCache" .. ""]
local function GetCache(forceClear)
  local pid = getOpenedProcessID()
  --if not pid or (pid == 0) then errn(2, "Game process not opened") end -- allow cache w/o opened process
  if not pid or (pid == 0) then log_err("Game process not opened") end -- allow cache w/o opened process

  if not _hlcgCache or (_hlcgCache.pid ~= pid) or forceClear then
    local old = _hlcgCache or {}
    _hlcgCache = {
      pid = pid, -- pid of the game (managed by c_gen.GetCache)
      gen_files = {}, -- set of filenames that were already generated and should be valid for the current pid
      tcclib_compiled = false, -- tcclib was not yet compiled for this pid
      c_dir = old.c_dir, -- dir for user c/h files
      g_dir = old.g_dir, -- dir for generated c/h files
    }
    _G._hlcgCache = _hlcgCache
  end
  return _hlcgCache, pid
end
--GetCache(true)
C.GetCache = GetCache
--]]

-- local function IsDir(path, desc)
local IsDir = U.IsDir

-- local function IsFile(path, desc)
local IsFile = U.IsFile

-- local function ReadFile(path)
local ReadFile = U.ReadFile

-- local function WriteFile(path, s)
local WriteFile = U.WriteFile


local function GetClsGenFileName(c)
  local r = format("gen/t.%s.h", c.name)
  return r
end
C.GetClsGenFileName = GetClsGenFileName


local function GetCType(pType, ctx)
  local isNew, byRef = false, true
  if not ctx then ctx = {} end
  local ct = ctx[pType]
  if not ct then
    local tn = T.ParseTypeName(pType)
    ct = tn and tn:gsub("[%$%.]", "_") or nil
    if ct then
      ctx[pType] = ct
      isNew = true
    else
      local k, kn = T.ParseTypeKind(pType)
      ct = hl_type_kind_c_type[k]
      byRef = false
    end
  end
  return ct, ctx, isNew, byRef
end
C.GetCType = GetCType


local function GenObjTypeFile(pType)
  local t = T.ParseType(pType)
  local c, pid, now = t[#t], getOpenedProcessID(), os.date("!%Y-%m-%d %H:%M:%S UTC")
  local super = c.super
  local genFileName = GetClsGenFileName(c)
  local defOnce = format("__%s__", genFileName:gsub("[/%.%$]", "_"))
  
  local ct, ctx, isNew, byRef = GetCType(pType, nil)
  local cct = ct

  local pre = {
    format("// gen time: %s, pid: 0x%08X (%u)", now, pid, pid),
    "",
    format("#ifndef %s", defOnce),
    format("#define %s", defOnce),
    "",
    "#include <common.h>",
  }

  local post = {
    format("#endif // %s", defOnce),
    "",
  }

  local tds = {
    format("typedef struct %s %s;", cct, cct),
  }

  local lns = {
    format("// type: %s, kind: %s, pType: 0x%012X", c.name, c.kind_name, c.pType),
    format("struct %s {", cct),
  }

  if super then
    local sfn = GetClsGenFileName(super)
    pre[#pre+1] = format("#include <%s>", sfn)
    pre[#pre+1] = ""

    lns[#lns+1] = format("  // super: %s", super.name)
    ct, ctx, isNew, byRef = GetCType(super.pType, ctx)
    lns[#lns+1] = format("  %-25s super;", ct)
  elseif c.kind == hl_type_kind.HOBJ then
    lns[#lns+1] = format("  hl_type* pType;")
  end

  lns[#lns+1] = ""

  lns[#lns+1] = format("  // cls: %s, begin_offset: 0x%04X", c.name, c.fields.begin_offset)
  for _, f in ipairs(c.fields) do
    --local ct, isNew, byRef
    ct, ctx, isNew, byRef = GetCType(f.pType, ctx)
    --local isPtr = (f.kind > hl_max_basic_type_kind)
    if isNew then --and byRef then
      tds[#tds+1] = format("typedef struct %s %s;", ct, ct)
    end
    local fn, k, kn, tn = f.name, f.kind, f.kind_name, f.type_name
    if fn == "" then fn = format("%s_0x%04X", f.kind_name, f.offset) end
    local ln = format("  %-25s %s;", byRef and (ct .. "*") or ct, fn)
    ln = format("%-47s // +%04X", ln, f.offset)
    if k > hl_max_basic_type_kind then
      ln = format("%s: %s%s", ln, kn, tn and (" " .. tn) or "")
    end
    lns[#lns+1] = ln
  end
  lns[#lns+1] = format("  // total_size: 0x%04X", c.fields.total_size)
  lns[#lns+1] = format("}; // %s (%s)", cct, c.name)
  lns[#lns+1] = ""

  local total_size = (c.fields.total_size + 7) & 0xFFFFFFF8
  lns[#lns+1] = format("_Static_assert(sizeof(%s) == 0x%04X, \"cls %s has wrong size\");", cct, total_size, c.name)
  lns[#lns+1] = ""

  --tds[#tds+1] = ""
  lns[#lns+1] = ""

  for _, m in ipairs(c.methods) do
    local ft, args = m.func_type, {}
    -- process method args
    for ai, at in ipairs(ft.arg_types) do
      ct, ctx, isNew, byRef = GetCType(at.pType, ctx)
      if isNew then --and byRef then
        tds[#tds+1] = format("typedef struct %s %s;", ct, ct)
      end
      local an = (ai == 1) and "obj" or format("arg%d", ai - 1)
      args[ai] = format("%s%s %s", ct, byRef and "*" or "", an)
    end

    -- process retVal
    local rt = ft.ret_type
    ct, ctx, isNew, byRef = GetCType(rt.pType, ctx)
    if isNew then --and byRef then
      tds[#tds+1] = format("typedef struct %s %s;", ct, ct)
    end
    local rct = format("%s%s", ct, byRef and "*" or "")

    -- the C func name must be unique so it will have to contain type name and method name
    local fn = format("%s_%s", cct, m.name)

    -- now when we have ret type and all arg types/names we can put them together
    -- make an extern func decl
    local argList = table.concat(args, ", ")
    local ln = format("extern %s %s(%s);", rct, fn, argList)
    lns[#lns+1] = ln

    -- make the function visible for TCC linker
    registerSymbol(fn, m.pFunc, true)
  end

  lns[#lns+1] = ""
  lns[#lns+1] = ""


  table.sort(tds)
  tds[#tds+1] = ""
  tds[#tds+1] = ""
  
  local rstrs = {
    table.concat(pre,  "\n"),
    table.concat(tds,  "\n"),
    table.concat(lns,  "\n"),
    table.concat(post, "\n"),
  }
  local r = table.concat(rstrs, "\n")
  return r
end
C.GenObjTypeFile = GenObjTypeFile


local function GenTypeFile(tn)
  local pType = hl.ResolveTypeName(tn)
  local k, kn = T.ParseTypeKind(pType)
  if k == hl_type_kind.HOBJ or k == hl_type_kind.HSTRUCT then
    return GenObjTypeFile(pType)
  end
  log_err("Can't parse type (%s) of kind %s", tn, kn)
end
C.GenTypeFile = GenTypeFile


local function GenFileCB(fn)
  -- analyze the file name to see what we have to generate
  local what, which = fn:match("^([t])%.(.+)%.h$")
  if what and which then
    if what == "t" then return GenTypeFile(which) end
    log_err("Unrecognized gen file kind \"%s\" (in %s)", what, fn)
  end
  log_err("Unrecognized gen file name \"%s\"", fn)
end
C.GenFileCB = GenFileCB
-- register our C file generator
CU._c_gens.hl_c_gen = GenFileCB



return C

