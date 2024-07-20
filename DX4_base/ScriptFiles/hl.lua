-- hl.lua
-- hashlink metadata integration to CE


local thisClsName = "hl"

local Base = require "Class"

-- comment out the next line to allow more debug info output
local function dbg(...) end

require("defines" .. "")
local serpent = require("serpent")
local T = require("hlType")

local function _cctor(C)
  --C.static.instances_mt.__mode = "" -- we don't want GC to collect registered instances
end

local C = Base:Subclass(thisClsName, _cctor)

-- class static store that should survive the lua files reload
local static = C.static
local instances = static.instances


-- load our circular dependencies
-- mark our module as loaded so that we can safely load them without stack overflow
local preload = require "preload"
preload.SetModuleResult(thisClsName, C)
-- circular deps (they also mark self as loaded before loading us)
-- NONE YET

local function ResolveTypeName(tn)
  local pBegin, pEnd, tar = T.FindMainTypeArray()
  if not pBegin then printf("No types found") err("No types found") end

  local hlCache = T.GetCache()
  local sc = hlCache.types.short.by_name[tn]
  if not sc then printf("Type \"%s\" not found", tn) err("no type %s", tn) end

  local pType = sc.pType
  return pType
end
C.ResolveTypeName = ResolveTypeName

--[[
AA ex:
hl_type_ptr(ent.Faction)
--]]
local function aa_define_type_ptr(arg)
  local tn = arg
  local pType = ResolveTypeName(tn)
  local res = format("define(%s_ptr,0x%012X)", tn, pType):gsub("%.", "_")
  dbg(res)
  return res
end

registerAutoAssemblerCommand("hl_type_ptr", aa_define_type_ptr)

local function ResolveField(arg)
  local pBegin, pEnd, tar = T.FindMainTypeArray()
  if not pBegin then printf("No types found") err("No types found") end
  
  local cn, fn = arg:match("^([^:]+):([^:]+)$")
  if not cn or not fn then printf("Invalid hl_field arg (\"%s\") format", arg) err("hl_field format") end
  
  local hlCache = T.GetCache()
  local sc = hlCache.types.short.by_name[cn]
  if not sc then printf("Cls \"%s\" not found", cn) err("no cls %s", cn) end

  local pType = sc.pType
  local co = T.ParseType(pType)
  local c = co[#co]
  for i, f in ipairs(c.fields) do
    if f.name == fn then
      return c, i
    end
  end
  printf("field \"%s\" not found in cls \"%s\"", fn, cn)
  err("no field %s", fn)
end


--[[
AA ex:
hl_field(ent.Faction:isAI)
--]]
local function aa_define_field(arg)
  local c, fi = ResolveField(arg)
  local f = c.fields[fi];
  local fo = f.offset
  local fs = format("%s_%s", c.name, f.name):gsub("%.", "_")
  registerSymbol(fs, f.offset)
  local res = format("define(%s,0x%04X)", fs, fo)
  print(res)
  return res

end

registerAutoAssemblerCommand("hl_field", aa_define_field)


local function ResolveMethod(methodFullName)
  local pBegin, pEnd, tar = T.FindMainTypeArray()
  if not pBegin then printf("No types found") err("No types found") end
  
  local cn, mn = methodFullName:match("^([^:]+):(.+)$")
  if not cn or not mn then printf("Invalid arg (methodFullName) format: \"%s\"", methodFullName) err("hl_method format") end
  
  local hlCache = T.GetCache()
  local sc = hlCache.types.short.by_name[cn]
  if not sc then printf("Cls \"%s\" not found", cn) err("no cls %s", cn) end
  if sc.kind ~= hl_type_kind.HOBJ then printf("Type %s is not HOBJ, but %s", cn, sc.kind_name) err("not HOBJ") end

  local pType = sc.pType
  local co = T.ParseType(pType)
  local c = co[#co]
  for i, m in ipairs(c.methods) do
    if m.name == mn then
      local mSym = format("%s_%s", c.name, m.name):gsub("%.", "_")
      registerSymbol(mSym, m.pFunc, true)
      return m, c, co
    end
  end
  printf("method \"%s\" not found in cls \"%s\"", mn, cn)
  err("no method %s", mn)
end
C.ResolveMethod = ResolveMethod


local function aa_define_method(arg)
  local m, c, co = ResolveMethod(arg)
  local ma = m.pFunc
  local res = format("define(%s_%s,0x%012X)", c.name, m.name, ma):gsub("%.", "_")
  print(res)
  return res
end

registerAutoAssemblerCommand("hl_method", aa_define_method)



local function aa_define_vt_offset(arg)
  local m, c, co = ResolveMethod(arg)
  local vt_offset = m.vt_offset
  if not vt_offset then printf("method \"%s:%s\" not in vt", cn, mn) err("method \"%s:%s\" not in vt", cn, mn) end
  local res = format("define(%s_%s_vt_offset,0x%04X)", c.name, m.name, vt_offset):gsub("%.", "_")
  print(res)
  return res
end

registerAutoAssemblerCommand("hl_vt_offset", aa_define_vt_offset)

local function GetDetourCache(addr)
  local pid = getOpenedProcessID()
  local dc = _G.hlDetourCache
  if not dc or (dc.pid ~= pid) then
    dc = {
      pid = pid,
      by_addr = {}
    }
    _G.hlDetourCache = dc
  end
  local c = dc.by_addr[addr]
  if not c then
    c = {}
    dc.by_addr[addr] = c
  end
  return c
end

local function aa_detour_method(arg, syntaxcheckonly)
  local m, c, co = ResolveMethod(arg)
  local ma = m.pFunc
  local mSym = format("%s_%s", c.name, m.name):gsub("%.", "_")
  registerSymbol(mSym, ma, true)

  local f4b = readInteger(ma)
  if f4b ~= 0xEC8B4855 then
    local msg = format("Method %s:%s (0x%012X) has unexpected prologue: 0x%08X", c.name, m.name, ma, f4b)
    wrn("%s", msg)
    return nil, msg
  end

  local minBytes = 6
  local asmLines, nBytes, orgBytesStr, orgBytes = util.DisassembleMinBytes(ma, minBytes)

  local rt = {
    format("define(%s,%012X)", mSym, ma),
    format("label(%s_org)", mSym),
    format("registerSymbol(%s_org)", mSym),
    format("label(%s_org_ret_addr)", mSym),
    format("label(%s_ret)", mSym),
    --format("label(%s_org_next)", mSym),
    "",
    "align 8 90",
    format("%s_org:", mSym),
    "  " .. table.concat(asmLines, "\n  "),
    format("  jmp [%s_org_ret_addr]", mSym),
    format("%s_org_ret_addr:", mSym),
    format("  dq %s+0x%04X", mSym, nBytes),
    --format("%s_org_next:", mSym),
    --format("%s_org_ret:", mSym),
    "",
    format("%s:", mSym),
    format("  push %s_new", mSym),
    format("  ret"),
    (nBytes > minBytes) and ("  nop\n"):rep(nBytes - minBytes) or "",
    format("%s_ret:", mSym),
    --format("\"%s_org_ret_addr+8\":", mSym),
    --format("%s_org_next+1:", mSym),
    --    "",
    --format("%s_org+10:", mSym),
    --"align 10 90",
    "",
  }


  local ret = table.concat(rt, "\n")

  dbg("\ngen by hl_detour_method(%s):\nENABLE:\n%s", arg, ret)

  local dt = {
    format("%s:", mSym),
    format("  db %s", orgBytesStr),
    "",
    format("unregisterSymbol(%s_org)", mSym),
  }
  local d = table.concat(dt, "\n")
  dbg("\nDISABLE:\n%s", d)

  local c = GetDetourCache(ma)
  c.disable = d
  c.addr = ma
  c.bytes = orgBytes

  return ret
end

registerAutoAssemblerCommand("hl_detour_method", aa_detour_method)



local function aa_restore_method(arg, syntaxcheckonly)
  local m, c, co = ResolveMethod(arg)
  local ma = m.pFunc
  local dc = GetDetourCache(ma)
  if not syntaxcheckonly then
    if not dc.bytes then
      local msg = format("Restore method data for %s:%s not found", c.name, m.name)
      return nil, msg
    end
    writeBytes(ma, dc.bytes)
    printf("method %s prologue bytes restored", arg)
  end
  return ""
end

registerAutoAssemblerCommand("hl_restore_method", aa_restore_method)

function hl_restore_method(arg)
  local r, msg = aa_restore_method(arg)
  if not r and msg then err(msg) end
  printf("method %s prologue bytes restored", arg)
end



return C
