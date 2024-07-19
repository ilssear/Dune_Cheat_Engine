-- preload.lua --
	
local lfs = require("lfs")

local cfg = {
  luaLoadSubDir = "lua",
  cLoadSubDir = "c",
  exportSubDir = "export",
}

local module_name = "preload"
local sep = package.config:sub(1, 1)

local function cwd()
  local res = lfs.currentdir()
  local ceDir = getCheatEngineDir():gsub(sep.."$", "")
  
  if res == ceDir then
    -- CE was probably opened standalone
    -- and cheat table was loaded with open file dialog
    res = getMainForm().OpenDialog1.InitialDir:gsub(sep.."$", "")
    --res = getMainForm().SaveDialog1.InitialDir:gsub(sep.."$", "")
  end
  --dbg("cwd: %s", res)
  return res
end

local _luaLoadStats = {
  fromFile = 0,
  fromTable = 0,
}

local function IsDeveloper()
  return _luaLoadStats.fromFile > _luaLoadStats.fromTable
end

local function TryLoadFile(path)
  local mode = "r"
	local f, e = io.open(path, mode)

  if not f then
    --dbg("Can't open lua file %s in %s mode (%s)", path, mode, e)
    return nil
  end

  local content = f:read("a")
  f:close()
  _luaLoadStats.fromFile = _luaLoadStats.fromFile + 1

  return content
end

local function TryLoadTableFile(fileName)
  local f = findTableFile(fileName)
  local src = f and f.Stream

  if not src then return nil end

  local dst = createStringStream()
  dst.Position = 0
  dst.copyFrom(src, src.Size)
  local content = dst.DataString

  --src.destroy()
  dst.destroy()
  _luaLoadStats.fromTable = _luaLoadStats.fromTable + 1

  return content
end

local function UpdateTableFile(fileName, content)
  local f = findTableFile(fileName)
  local dst = f and f.Stream

  if not f then
    f = createTableFile(fileName)
    dst = f.Stream
  else
    dst.Size = 0
    dst.Position = 0
  end

  local src = createStringStream(content)
  dst.copyFrom(src, src.Size)
  src.destroy()
  --dst.destroy()
end

local function LuaFileLoader(modName)
  local script, path = nil, nil
  local fileName = modName .. ".lua"
  local isFile = false
  --dmp("Loading lua module: %s", modName)
  local loadDir = cfg.luaLoadSubDir and (cwd() .. sep .. cfg.luaLoadSubDir)

  if loadDir then
    path = (loadDir .. sep .. fileName)
    script = TryLoadFile(path)
  end

  if script then
    isFile = true
  else
    script = TryLoadTableFile(fileName)
  end

  if script then
    if isFile then
      dbg("Module %s loaded from file %s", modName, path)
      UpdateTableFile(fileName, script)
    else
      dbg("Module %s loaded from cheat table", modName)
    end
    local fn = load(script)
    local ok, res = xpcall(fn, xerr, modName, isFile and path or fileName)
    if ok then return res end
    local msg = format("Error in module %s:\n%s", fileName, res)
    error(msg, 2)
  else
    local msg
    if path then
      msg = format("Module %s not found (tried to load it from file %s, then from cheat table)", modName, path)
    else
      msg = format("Module %s not found in cheat table", modName)
    end
    dbg(msg)
    errn(2, msg)
  end
end

local function LuaFilesPreload(luaFiles, clearCached)
  for _, name in ipairs(luaFiles) do
    package.preload[name] = LuaFileLoader
    if clearCached and (package.loaded[name] ~= nil) then
    	package.loaded[name] = nil
      dbg("Module %s marked for fresh preload)", name)
    else
      dbg("Module %s marked for preload)", name)
    end
  end
end

local function SetModuleResult(name, result)
  package.loaded[name] = result
  if result ~= nil then
    dbg("Module %s marked as loaded", name)
  else
    dbg("Module %s marked as NOT loaded", name)
  end
end

local C = {
  cfg = cfg,
  cwd = cwd,
  IsDeveloper = IsDeveloper,
  TryLoadFile = TryLoadFile,
  TryLoadTableFile = TryLoadTableFile,
  UpdateTableFile = UpdateTableFile,
  LuaFilesPreload = LuaFilesPreload,
  SetModuleResult = SetModuleResult,
}

package.loaded[module_name] = C
	
