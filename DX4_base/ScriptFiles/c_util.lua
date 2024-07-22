
-- c_util.lua
-- C code runner (for AA {$C})

local thisClsName = "c_util"

local Base = require "Class"

if not log_dbg or not log_verbose or not log_info or not log_warn or not log_err then
  log_dbg = log_dbg or function(fmt, ...) end
  log_verbose = log_verbose or function(fmt, ...) end
  log_info = log_info or function(fmt, ...) end
  log_warn = log_warn or function(fmt, ...) end
  log_err = log_err or function(fmt, ...) end
end

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

require("defines".."")
local lfs = require("lfs".."")
local serpent = require("serpent".."")
local U = require("util".."")
local MR = require("MemRec".."")
local sep = package.config:sub(1, 1)
local sep2x = sep .. sep

-- local function IsDir(path, desc)
local IsDir = U.IsDir

-- local function IsFile(path, desc)
local IsFile = U.IsFile

-- local function ReadFile(fn)
local ReadFile = U.ReadFile

-- local function WriteFile(fn, s)
local WriteFile = U.WriteFile

local _cCache = _G["_cCache" .. ""]
local function GetCache(forceClear)
  local pid = getOpenedProcessID()
  
  if (not pid or (pid == 0)) then log_err("Game process not opened (c_util)") end -- allow cache w/o opened process
  local cwd, isDev = U.GetWorkDir()

  if not _cCache or (_cCache.pid ~= pid) or forceClear then
    cwd, isDev = U.GetWorkDir({ "c", "c" .. sep .. "gen", })
    local old = _cCache or {}

    _cCache = {
      pid = pid,
      isDev = isDev,
      -- dir for user c/h files
      c_dir = cwd .. sep .. "c",
      -- dir for generated c files
      g_dir = cwd .. sep .. "c" .. sep .. "gen",
      -- map name->func(relPath) of c/h file generators
      --    relPath is relative to c_dir, so it begins with "gen/"
      gens = C._c_gens,
      -- map filename->hash of files that were already
      --   exported from or imported to cheat table
      --   if isDev then importing to else exporting from table
      c_files = old.c_files or {},
      include_paths = {},
      tcclib_compiled = false, -- tcclib was not yet compiled for this pid
      -- name -> func callbacks that have to be called
      --   when cache is migrated (by forceClear or due to pid change)
      migration_callbacks = C._cache_migration_callbacks,
    }
    _G._cCache = _cCache
    for id, func in pairs(_cCache.migration_callbacks) do
      func(old, _cCache)
    end
  end
  return _cCache, pid
end
--GetCache(true)
C.GetCache = GetCache


local function AddIncludePaths(paths)
  local cca, pid = GetCache()
  local inc = cca.include_paths
  for _, path in ipairs(paths) do
    if not inc[path] then
      addCIncludePath(path)
      inc[path] = true
    end
  end
end
C.AddIncludePaths = AddIncludePaths


local function CacheMigrationCB(old, new)
  if new.pid then
    AddIncludePaths({ new.c_dir }) --, new.g_dir })
    local fns = U.Dir(new.g_dir)
    for i, fn in ipairs(fns) do
      local path = new.g_dir .. sep .. fn
      log_verbose("deleting old gen file: %s", fn)
      os.remove(path)
    end
  end
end


-- init our cache migration callbacks
C._cache_migration_callbacks = {
  c_util = CacheMigrationCB,
}

-- init also C file generators
C._c_gens = {}

local function IsGenFileName(fn)
  return fn:find("^gen/")
end
C.IsGenFileName = IsGenFileName

local function GenFile(relPath)
  for name, gen in pairs(C._c_gens) do
    local s = gen(relPath)
    if s then
      return s
    end
  end
  log_err("No file generator found for file name \"%s\"", relPath)
end
C.GenFile = GenFile

local function GetCDirs()
  local cache = GetCache()
  local c_dir, g_dir, isDev = cache.c_dir, cache.g_dir, cache.isDev
  return c_dir, g_dir, isDev
end
C.GetCDirs = GetCDirs
GetCDirs()


local function FindOrGenCFile(fname)
  local c_dir, g_dir, isDev = GetCDirs()
  local ok, path = false, nil
  if IsGenFileName(fname) then
    -- the file name tells us that we should generate the file
    -- so generate it from metadata
    -- fname should already contain the "gen/" prefix, so strip it down
    fname = fname:gsub("^gen/", "")
    path = g_dir .. sep .. fname
    local s = GenFile(fname)
    log_verbose("file %s generated from metadata to %s", fname, path)
    WriteFile(path, s)
    ok = true
  else
    -- look if the file exists
    path = c_dir .. sep .. fname
    ok = lfs.attributes(path, "mode")
    if ok then
      -- we should save it to the cheat table
      log_verbose("Updating table file %s from %s", fname, path)
      local s = ReadFile(path)
      preload.UpdateTableFile(fname, s)
    elseif not isDev then
      -- we don't have this file (yet)
      -- but we are in export mode so try to export it from cheat table
      local s = preload.TryLoadTableFile(fname)
      --if not s then return nil end -- no such file, C compiler will load it from CE dir or raise the error
      if s then
        log_verbose("exporting C file %s from cheat table to %s", fname, c_dir)
        WriteFile(path, s)
        ok = true
      end
    end
  end
  if not ok then return nil, format("C file not found: %s", fname) end
  return path, nil
end
C.FindOrGenCFile = FindOrGenCFile

local _include_file_scan_blacklist = {
  ["hl.h"] = true,
}

local function CheckCFileIncludes(path, flist)
  local fname = extractFileName(path)
  if _include_file_scan_blacklist[fname] then
    return true, format("file name on blackist for scanning includes: %s", fname), flist
  end

  log_dbg("checking includes in %s", path)
  local ok = true
  local f, msg = io.open(path, "r")
  if not f then log_err("file (%s) open (r) error: %s", path, msg) end
  
  -- process any #include <...> lines from the file recursively
  local lnc, ic = 0, 0
  for ln in f:lines("*l") do
    lnc = lnc + 1
    local fn = ln:match("^#include[%s]+<(.+)>[\r\n]*$")
    if fn and not (flist and flist[fn]) then
      ic = ic + 1
      log_dbg("found include: %s", fn)
      ok, msg = C.CheckCFile(fn, flist)
      if not ok then print(msg) end -- just print error as the file may still exist elsewhere
    end
  end
  log_dbg("total %d includes found in %d lines of %s", ic, lnc, path)
  f:close()
  return true, format("file checked: %s", fname), flist
end
C.CheckCFileIncludes = CheckCFileIncludes


local function CheckCFile(fname, flist)
  -- avoid creating the same file many times in one round
  if flist and flist[fname] then return true, format("file aready checked: %s", fname), flist
  elseif not flist then flist = { fname }
  else flist[fname] = true
  end

  -- try to get the file
  local path, msg = FindOrGenCFile(fname)
  if not path then return nil, msg, flist end

  -- parse the file and check its includes
  local ok
  ok, msg = CheckCFileIncludes(path, flist)
  return ok, msg, flist
end
C.CheckCFile = CheckCFile


local function CheckCFiles(fnames, flist)
  local cfsok, cfok, msg = false, nil, nil
  for findex, fname in ipairs(fnames) do
    cfok, msg, flist = CheckCFile(fname, flist)
    if not cfok then return nil, msg end
    cfsok = true
  end
  return cfsok, msg or ((not cfsok) and "no C files specified"), flist
end
C.CheckCFiles = CheckCFiles


local function CheckCStringsIncludes(lines, syntaxcheck)
  local lnc, ic, flist = lines.Count, 0, nil
  for i = 0, lnc - 1 do
    local ln = lines.getString(i)
    --printf("[%03d] \"%s\"", i + 1, ln)
    -- find included file name
    --i.e. #include <Structure.onSelect.c>
    local fn = ln:match("^#include[%s]+<(.+)>[\r\n]*$")
    if fn then
      ic = ic + 1
      log_dbg("found include: %s", fn)
      local ok, msg, flist = CheckCFile(fn, flist)
      if not ok then print(msg) end -- just print error as the file may still exist elsewhere
    end
  end
  log_dbg("total %d includes found in %d lines of C script", ic, lnc)
end


local function IncludeCheckerAutoAssemblerPrologue(sls, syntaxcheck)
  log_dbg("%s aa prologue handler got a call (syntaxcheck = %s)", thisClsName, syntaxcheck)
  --if syntaxcheck then -- check includes only during syntaxcheck as the gen files should still exist after that
    CheckCStringsIncludes(sls)
  --end
end

local function UpdateIncludeCheckerAutoAssemblerPrologue()
  if _includeCheckerAutoAssemblerPrologueId then
    unregisterAutoAssemblerPrologue(_includeCheckerAutoAssemblerPrologueId)
    log_dbg("%s unregistered old aa prologue handler %s", thisClsName, _includeCheckerAutoAssemblerPrologueId)
  end
  _includeCheckerAutoAssemblerPrologueId = registerAutoAssemblerPrologue(IncludeCheckerAutoAssemblerPrologue, false)
  log_dbg("%s registered new aa prologue handler %s", thisClsName, _includeCheckerAutoAssemblerPrologueId)
end
UpdateIncludeCheckerAutoAssemblerPrologue()


-- C File Compilation
local function CompileCFiles(fnames, doNotRegisterSymbols, targetAddr)
  if type(fnames) == "string" then
    fnames = string.split2t(fnames, ",")
    local nfnames = #fnames
    for i = 1, nfnames do
      log_verbose("fnames[%d] = \"%s\"", i, fnames[i])
      fnames[i] = fnames[i]:trim()
    end
  end

  local cfok, msg = CheckCFiles(fnames)
  if not cfok then return cfok, msg end

  local cache = GetCache()
  if not cache.tcclib_compiled then
    compileTCCLib()
    cache.tcclib_compiled = true
  end

  local paths = {}
  for i, fname in ipairs(fnames) do
    local path = cache.c_dir .. sep .. fname
    paths[i] = path
  end

  local curMR = MR.GetCurrent() -- get current memory record (if any)

  local c_syms, syms = nil, {}
  c_syms, msg = compileFiles(paths, targetAddr)
  if c_syms then
    for n, a in pairs(c_syms) do
      syms[#syms+1] = { n, a }
    end
    table.sort(syms, function (a, b) return a[2] < b[2] end)

    log_verbose("\nC: %s symbols defined in %s:", #syms, table.concat(fnames, ", ")) --, serpent.block(c_syms, {numformat = "0x%012X"})*/)
    if curMR then
      curMR:registerSymbols(syms)
    else
      for _, s in ipairs(syms) do
        local sym, addr = s[1], s[2]
        log_verbose("  %-20s: 0x%012X", sym, addr)
        if not curMR and not doNotRegisterSymbols then
          registerSymbol(sym, addr, true)
        end
      end
    end
  else
    log_err("\nerrors in %s:\n%s", table.concat(fnames, ", "), msg)
    return nil, msg
  end
  return syms, nil, c_syms
end
C.CompileCFiles = CompileCFiles


local function CompileCFile(fname, doNotRegisterSymbols, targetAddr)
  return CompileCFiles({ fname }, doNotRegisterSymbols, targetAddr)
end
C.CompileCFile = CompileCFile


if not _tempCodeSize then
  _tempCodeSize = 0x10000
end
--_tempCodeAddr

local function aa_c_files(arg, syntaxcheck)
  local curMR = MR.GetCurrent() -- get current memory record (if any)

  local targetAddr, symPrefix = nil, nil
  if curMR and not syntaxcheck then
    targetAddr = curMR:alloc()
    symPrefix = curMR:getSymPrefix()
  else
    if not _tempCodeAddr then
      _tempCodeAddr = allocateMemory(_tempCodeSize)
    end
    targetAddr = _tempCodeAddr
  end

  local doNotRegisterSymbols = syntaxcheck
  local syms, msg = C.CompileCFiles(arg, doNotRegisterSymbols, targetAddr)
  if not syms then return nil, msg end

  local rt = {}
  for i, s in ipairs(syms) do
    local sym, addr = ((symPrefix or "") .. s[1]), s[2]
    rt[i] = format("define(%s,0x%012X)", sym, addr)
  end
  local r = table.concat(rt, "\n")
  return r, nil
end
C.aa_c_files = aa_c_files

registerAutoAssemblerCommand("hl_c_files", aa_c_files)


local function aa_c_file(arg, syntaxcheck)
  return aa_c_files({ arg }, syntaxcheck)
end
C.aa_c_file = aa_c_file

registerAutoAssemblerCommand("hl_c_file", aa_c_file)


return C