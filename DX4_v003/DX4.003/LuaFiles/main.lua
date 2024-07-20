-- main.lua --
require "err"
local clearCachedLuaFiles = true
local preload = require "preload"

-- Preload the simple_logger
preload.LuaFilesPreload({"simple_logger"}, clearCachedLuaFiles)

-- Load the simple_logger module in main
logger = require("simple_logger")
logger.setLevel(logger.levels.INFO) -- Default to ERROR logging (Other levels: ALL, DEBUG, INFO, WARN, ERROR)

-- Create global aliases
_G.log_dbg = logger.debug
_G.log_verbose = logger.verbose
_G.log_info = logger.info
_G.log_warn = logger.warn
_G.log_err = logger.error

-- Files below may require the simple_logger
-- Continue preloading files: hl library
local preLoadLuaFiles = {
  "inflate-bwo", "zzlib",
  "hlMain", "hlUtil", "hlType", "hl", "hlDump", 
}
preload.LuaFilesPreload(preLoadLuaFiles, clearCachedLuaFiles)

-- Continue preloading files
local loadLuaFiles = {
  "serpent",
  "stop_watch",
  "tables",
  "Class",
  --"TestClass",
  "util",
  "MemRec",
  "c_util",
  --"addrListTT",
  "hlMain", "hl_c_gen",
}
preload.LuaFilesPreload(loadLuaFiles, clearCachedLuaFiles)

for _, luaFile in ipairs(loadLuaFiles) do
  _G[luaFile] = require(luaFile)
end

	
