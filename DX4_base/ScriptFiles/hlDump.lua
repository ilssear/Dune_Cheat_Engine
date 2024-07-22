-- hlDump.lua
-- Dumps hashlink runtime metadata (types, fields, methods, ...)


local thisClsName = "hlDump"

local Base = require "Class"

if not log_dbg or not log_verbose or not log_info or not log_warn or not log_err then
  log_dbg = log_dbg or function(fmt, ...) end
  log_verbose = log_verbose or function(fmt, ...) end
  log_info = log_info or function(fmt, ...) end
  log_warn = log_warn or function(fmt, ...) end
  log_err = log_err or function(fmt, ...) end
end


require("defines" .. "")
local serpent = require("serpent")
local T = require("hlType")
local hl = require("hl")

local function _cctor(C)
  --C.static.instances_mt.__mode = "" -- we don't want GC to collect registered instances
end

local C = Base:Subclass(thisClsName, _cctor)

-- class static store that should survive the lua files reload
local static = C.static
local instances = static.instances

--[[
-- load our circular dependencies
-- mark our module as loaded so that we can safely load them without stack overflow
local preload = require "preload"
preload.SetModuleResult(thisClsName, C)
-- circular deps (they also mark self as loaded before loading us)
-- NONE YET
--]]




function DumpParseType(pType)
  if type(pType) == "string" then
    pType = hl.ResolveTypeName(pType)
  end
  local t = T.ParseType(pType)
  log_verbose("t = %s", serpent.block(t, { numformat = "0x%04X" }))
  return t
end


function FindFunc(pFunc)
  -- get fresh types
  local pBegin, pEnd, tar = T.FindMainTypeArray()

  -- select only object types
  local mods, hObj = {}, hl_type_kind.HOBJ
  for _, t in ipairs(tar) do
    if t.kind == hObj then
      local pType = t.pType
      local tobj = readPointer(pType + 0x08)
      local pModCtx = readPointer(tobj + 0x40)
      -- look for the module in known modules first
      local mod = mods[pModCtx]
      if not mod then
        -- this is a new pModCtx, add it to our lookup
        mod = {
          ppFunc = readPointer(pModCtx + 0x08),
          ppFuncT = readPointer(pModCtx + 0x10),
          maxIdx = -1,
        }
        mods[pModCtx] = mod
      end
      -- get object method table
      local nproto, pProtos = readInteger(tobj + 0x04), readPointer(tobj + 0x28)
      -- look in object methods for our pFunc
      local ppFunc = mod.ppFunc
      for i = 1, nproto do
        local pProto = pProtos + (i - 1) * 0x18
        local findex = readInteger(pProto + 0x08) -- hl_obj_proto.findex
        local pF = readPointer(ppFunc + findex * 0x08)
        -- is it the func we are looking for?
        if pF == pFunc then
          -- bingo!
          local pName = readPointer(tobj + 0x10)
          local pMethodName = readPointer(pProto + 0x00)
          local ppFuncT = mod.ppFuncT
          local pFuncT = readPointer(ppFuncT + findex * 0x08)
          local res = {
            pFunc = pF,
            --pFuncType = pFuncT,
            func_type = T.ParseType(pFuncT),
            pType = pType,
            tName = readString(pName, 1024, true),
            mindex = i - 1,
            method_name = readString(pMethodName, 1024, true),
          }
          log_verbose("fn = %s", serpent.block(res, { numformat = "0x%04X" }))
          return res
        end
      end
    end
  end

  -- look for unique module contexts
  
  --local kind, kind_name = C.ParseTypeKind(pType)
  --if not kind then return nil, kind_name end -- kind_name should contain err msg

end


function DumpMethod(mn)
  if type(mn) == "number" then FindFunc(mn) return end
  
  local m, c, co = hl.ResolveMethod(mn)
  if m then
    log_verbose("%s = %s", mn, serpent.block(m, { numformat = "0x%04X" }))
    log_info("%s = 0x%012X", mn, m.pFunc)
  else
    log_err("Method %s not found", mn)
  end
end




return C
