-- util.lua --

local definesModuleName = "defines" -- from CE
require(definesModuleName)

require "err"

if not log_dbg or not log_verbose or not log_info or not log_warn or not log_err then
  log_dbg = log_dbg or function(fmt, ...) end
  log_verbose = log_verbose or function(fmt, ...) end
  log_info = log_info or function(fmt, ...) end
  log_warn = log_warn or function(fmt, ...) end
  log_err = log_err or function(fmt, ...) end
end

local format = string.format

local  module_name = "util"
log_verbose("begin CT LUA script %s", module_name)

local lfs = require("lfs".."")
local preload = require("preload".."")

-- shallow table copy
function table_copy(t)
  return {table.unpack(t)}
end


-- trims given chars or whitespaces from left and right side of the self string
function string:trim(tch)
  return self:rtrim(tch):ltrim(tch)
end

-- trims given chars or whitespaces from the left side of the self string
function string:ltrim(tch)
  local pat = "^[%s]+(.-)$"
  if tch then
    pat = pat:format(tch, tch)
    log_dbg("lpat: \"%s\"", pat)
  end
  local r = self:match(pat)
  return r or self
end

-- trims given chars or whitespaces from left and right side of the self string
function string:rtrim(tch)
  local pat = "^(.-)[%s]+$"
  if tch then
    pat = pat:format(tch, tch)
    log_dbg("rpat: \"%s\"", pat)
  end
  local r = self:match(pat)
  return r or self
end

-- splits the string by delim or by whitespace chars into table (array)
function string:split2t(sep, tres)
  sep = sep or '%s'
  local t = tres or {}
  --for str, s in string.gmatch(inputstr, "([^"..sep.."]*)("..sep.."?)") do
  for str in self:gmatch("([^"..sep.."]+)") do
    t[#t+1] = str
    --if s == "" then return t end
  end
  return t
end

-- splits the string by delim or by whitespace char into table (array)
function string:split2t_exact(sep, tres)
  if (type(sep) ~= "string") or (sep:len() == 0) then
    log_err("string:split_exact(sep) arg1 (sep) expected non-empty string, got \"%s\" (%s)", sep, type(sep))
  end

  local t = tres or {}
  if #self > 0 then
    --for str, s in string.gmatch(inputstr, "([^"..sep.."]*)("..sep.."?)") do
    for str, sp in self:gmatch("([^"..sep.."]*)("..sep.."?)") do
      t[#t+1] = str
      if sp == "" then break end
    end
  end
  return t
end

function string:escape_pattern()
  return self:gsub("([^%w])", "%%%1")
end

local C = {
}


local function ParseParams(params)
  local str_t = {}
  for _, str in (","..params):gmatch("(,)([^,]*)") do
    str_t[#str_t+1] = str
  end
  return str_t
end
C.ParseParams = ParseParams


local function ParseParamsUnpacked(params)
  local str_t = ParseParams(params)
  return table.unpack(str_t)
end
C.ParseParamsUnpacked = ParseParamsUnpacked


local function AobScanRange1R(str_addr, len, str_bytes, protectionFlags)
  log_dbg("soExactValue: %s", soExactValue)
  log_dbg("vtByteArray: %s", vtByteArray)
  log_dbg("rtRounded: %s", rtRounded)
  ----[[
  --local bytes_to_find = "48 8D 0C 49 83 C1 19"
  local addr = getAddressSafe(str_addr)
  if not addr then log_err("Unable to resolve addr = arg1 to AobScanRange1R() = \"%s\"", str_addr) end
  log_dbg("scan for %s from addr: 0x%08X (%s)", str_bytes, addr or 0, str_addr)

  if type(len) == "string" then len = tonumber(len, 16) end

  local function doScan(sc)
    sc.OnlyOneResult = true
    local scRet = sc.firstScan(
      soExactValue, -- scanoption
      vtByteArray, -- vartype
      rtRounded, --rtRounded, -- roundingtype
      str_bytes, -- input1
      "", -- input2
      addr, -- startAddress
      addr + len, -- stopAddress
      protectionFlags or "*W*R*X", -- protectionflags ("+W+X" = Read/Write/Exec)
      0, -- alignmenttype (no alignment check)
      "1", -- "alignmentparam"
      true, -- isHexadecimalInput
      true, -- isNotABinaryString
      false, -- isunicodescan
      false  -- iscasesensitive
    )
    log_dbg("scRet: %s", scRet)
    sc.waitTillDone()
    local res = sc.Result
    log_dbg("found: 0x%08X", res or 0)
    return res
  end

  local sc = createMemScan()
  local ok, res = xpcall(doScan, xerr, sc)
  sc.destroy()
  log_dbg("ok: %s, found: 0%08X", ok, res or 0)
  return ok, res
end
C.AobScanRange1R = AobScanRange1R


local function aa_cmd_aobScanRange1RAsDefine(params, syntaxcheck)
  local str_t = {}
  for _, str in (","..params):gmatch("(,)([^,]*)") do
    str_t[#str_t+1] = str
  end
  local define_as, str_addr, str_len, str_bytes, str_protect = ParseParamsUnpacked(params)
  local ok, res = AobScanRange1R(str_addr, str_len, str_bytes, str_protect)
  if not ok then error("AobScanRange1R("..params.."): ".. res, 3) end
  if not res then errn(3, "AobScanRange1R(%s) did not found matching bytes", params) end
  return format("define(%s,0x%08X)", define_as, res)
end
C.aa_cmd_aobScanRange1RAsLabel = aa_cmd_aobScanRange1RAsDefine

registerAutoAssemblerCommand("aobScanRange1RAsDefine", aa_cmd_aobScanRange1RAsDefine)


local function aa_cmd_RegisterLabelHere(params, syntaxcheck)
  local n = params
  return ("label(%s)\nregistersymbol(%s)\n%s:"):format(n, n, n)
end

registerAutoAssemblerCommand("reg", aa_cmd_RegisterLabelHere)


local function aa_cmd_UnRegisterLabel(params, syntaxcheck)
  local n = params
  return ("unregistersymbol(%s)"):format(n)
end
registerAutoAssemblerCommand("unreg", aa_cmd_UnRegisterLabel)


local function DisassembleMinBytes(addr, minBytes)
  local a = (type(addr) == "number") and addr or getAddressSafe(addr)
  if not a then log_err("Disassemble(%s, %s) invalid addr (arg1)", addr, minBytes) end

  local begin, asmLines, bytesStrLines, nBytesTotal = a, {}, {}, 0
  while nBytesTotal < minBytes do
    -->> disassemble(address): Disassembles the given address and returns a string in the format of "address - bytes - opcode : extra"
    local ds = disassemble(a)
    log_verbose("ds: %s", ds)
    if not ds then err("Disassemble(%s, %s) inaccessible addr (0x%012X)", addr, minBytes, a) end
    
    -->> splitDisassembledString(disassembledstring): Returns 4 strings. The address, bytes, opcode and extra field
    -->>>> BUT CE 7.4 returns them IN REVERSE ORDER
    local ex, op, bs, as = splitDisassembledString(ds);
    log_dbg("as: %s", as)
    log_dbg("bs: %s", bs)
    log_dbg("op: %s", op)
    log_dbg("ex: %s", ex)

    asmLines[#asmLines+1] = op
    bytesStrLines[#bytesStrLines+1] = bs

    local nBytes = getInstructionSize(a)
    a = a + nBytes
    nBytesTotal = nBytesTotal + nBytes
  end

  local bytes = readBytes(begin, nBytesTotal, true)
  local bytesStr = table.concat(bytesStrLines, " ")

  return asmLines, nBytesTotal, bytesStr, bytes
end
C.DisassembleMinBytes = DisassembleMinBytes


local function IsDir(path, desc)
  local mode, msg = lfs.attributes(path, "mode")
  if not mode or (mode ~= "directory") then
    if desc then
      log_warn("no %s (%s): %s", desc, path, msg or mode)
    end

    return false, mode
  end

  if desc then
    log_info("%s: \"%s\"", desc, path)
  end

  log_verbose("attrs: %s", serpent.line(ok))
  return true, mode
end
C.IsDir = IsDir


local function IsFile(path, desc)
  local mode, msg = lfs.attributes(path, "mode")
  if not mode or (mode ~= "file") then
    if desc then
      log_verbose("no %s (%s): %s", desc, path, msg or mode)
    end
    return false, mode
  end
  if desc then
    log_verbose("%s: \"%s\"", desc, path)
  end
  --log_verbose("attrs: %s", serpent.line(ok))
  return true, mode
end
C.IsFile = IsFile


local function ReadFile(path)
  local f, msg = io.open(path , "r")
  if not f then log_err("file (%s) open (r) error: %s", path, msg) end

  local s
  s, msg = f:read("*a")
  f:close()
  if not s then log_err("file (%s) read error: %s", path, msg) end
  return s
end
C.ReadFile = ReadFile


local function WriteFile(path, s)
  local f, msg = io.open (path , "w+")
  if not f then log_err("file (%s) open (w+) error: %s", path, msg) end

  local ok
  ok, msg = f:write(s)
  f:close()
  if not ok then log_err("file (%s) write error: %s", path, msg) end
end
C.WriteFile = WriteFile

-- dir/file (in path) separator "/" or "\\""
local sep = package.config:sub(1, 1)


-- returns path and bool
--   path is the main local directory where subDirs exist
--   bool is true if we are in developer mode
--     main dir is the dir where the cheat table was loaded from
--     all subdirs plus "lua" subdir were already there
--     used files will be used to update table files
--   bool is false if we are in user mode
--     main dir is temp dir
--     all subdirs were created if missing
local function GetWorkDir(subDirs)
  local cwd, isDev
  local wdi = _G["_workDirInfo"..""]
  if wdi then
    cwd, isDev = wdi.dir, wdi.isDev
  else
    cwd, isDev = preload.cwd(), preload.IsDeveloper()
    if not isDev then
      cwd = os.tmpname()
      local ok, msg, errCode = lfs.mkdir(cwd)
      if not ok then
        log_err("Can't create main dir %s (%s, %s)", cwd, msg, errCode)
      end
    end
    wdi = { dir = cwd, isDev = isDev, }
    _G._workDirInfo = wdi
  end
  -- we have the main directory, should we create subdirs?
  if subDirs then
    if type(subDirs) == "string" then
      subDirs = { subDirs }
    elseif type(subDirs) ~= "table" then
      log_err("arg1 (subDirs) expected table or string, got %s (%s)", type(subDirs), subDirs)
    end
    for i, sd in ipairs(subDirs) do
      local d = cwd .. sep .. sd
      if IsDir(d, nil) then
        log_verbose("subdir %s in %s exists", sd, cwd)
      else
        local ok, msg, errCode = lfs.mkdir(d)
        if not ok then
          log_err("Can't create subdir %s in %s (%s, %s)", sd, cwd, msg, errCode)
        end
        log_verbose("created subdir %s in %s", sd, cwd)
      end
    end
  end
  return cwd, isDev
end
C.GetWorkDir = GetWorkDir


local function Dir(dir)
  local t = {}
  --[[
    iter, dir_obj = lfs.dir (path)
    Lua iterator over the entries of a given directory. Each time the iterator is called
      with dir_obj it returns a directory entry's name as a string, or nil if there are
      no more entries. You can also iterate by calling dir_obj:next(), and explicitly
      close the directory before the iteration finished with dir_obj:close(). Raises an
      error if path is not a directory.
  ]]
  for fn in lfs.dir(dir) do
    if (fn ~= ".") and (fn ~= "..") then t[#t+1] = fn end
  end
  return t
end
C.Dir = Dir


log_verbose("end CT LUA script %s", module_name)

return C
