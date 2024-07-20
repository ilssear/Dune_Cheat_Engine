-- MemRec.lua`

-- maintains the "current" script memory record being compiled
-- remembers the active memory records (those that were successfully compiled and activated)
-- uses global event handlers for memory records

local thisClsName = "MemRec"
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


--local T = require("hlType")
--local hl = require("hl")


local _mrCache = _G["_mrCache" .. ""]
local function GetCache(forceClear)
  local pid = getOpenedProcessID()
  --if not pid or (pid == 0) then log_err("Game process not opened (MemRec)") end

  if not _mrCache or (_mrCache.pid ~= pid) or forceClear then
    local old = _mrCache or {}
    
    -- destroy existing MR instances
    local byId = _mrCache and old.memrecs.byId or {}
    for n, o in pairs(byId) do o:Destroy("purge cache") end

    _mrCache = {
      pid = pid, -- pid of the game
      memrecs = { -- cache for memory records
        byId = {}, -- id -> instance map of all known memrecs
        curId = nil, -- id of the currently compiled/processed memrec (from global events)
      },
      -- preserve old handlers or they get lost
      handlers = old.handlers or {
        preExec = {},
        postExec = {},
        preActivate = {},
        postActivate = {},
        preDeactivate = {},
        postDeactivate = {},
      },
    }
    _G._mrCache = _mrCache
  end
  return _mrCache, pid
end
--GetCache(true)
C.GetCache = GetCache



local function aa_sym_prefix(arg)
  local obj = C.GetCurrent()
  if not obj then return nil, format("sym_prefix(%s) no current MemRec instance", arg) end

  obj:setSymPrefix(arg)
end

registerAutoAssemblerCommand("sym_prefix", aa_sym_prefix)


----------------------------------------------------------------------------------
--                           E V E N T S
----------------------------------------------------------------------------------

function C.RegisterPreExecHandler(name, handler)
  local c = GetCache()
  local handlers = c.handlers.preExec
  handlers[name] = handler
end

function C.UnregisterPreExecHandler(name)
  local c = GetCache()
  local handlers = c.handlers.preExec
  handlers[name] = nil
end


local function OnEvent(evtName, ...)
  local c = GetCache()
  local handlers = c.handlers and c.handlers[evtName] or nil
  if not handlers then log_warn("no such handlers: %s", evtName) return nil end

  for n, h in pairs(handlers) do
    local ok, msg = xpcall(h, xerr, ...)
    if not ok then
      log_warn("\nERROR in MemRec %s event handler %s:\n%s\n", evtName, n, msg)
    end
  end
end


--[[
global events
  function onMemRecPreExecute(memoryrecord, newstate BOOLEAN):
    If above function is defined it will be called before action* has been performed.
    Active property is about to change to newState.
  
  function onMemRecPostExecute(memoryrecord, newState BOOLEAN, succeeded BOOLEAN):
    If above function is defined it will be called after action*.
    Active property was supposed to change to newState.
    If 'succeeded' is true it means that Active state has changed and is newState.
    
    newState and succeeded are read only.
  
    *action can be: running auto assembler script (ENABLE or DISABLE section), freezing and unfreezing.
--]]

function onMemRecPreExecute(mr, newState)
  return C.OnMemRecPreExecute(mr, newState)
end

function onMemRecPostExecute(mr, newState, succeeded)
  C.OnMemRecPostExecute(mr, newState, succeeded)
end


function C.OnMemRecPreExecute(mr, newState)
  local obj = C.GetOrCreateById(mr.ID)
  if not obj then
    log_warn("MemRec.GetOrCreateById(%02d) returned nil", mr.ID)
    return
  end
  obj:onPreExec(mr, newState, succeeded)
end


function C.OnMemRecPostExecute(mr, newState, succeeded)
  local obj = C.GetOrCreateById(mr.ID)
  if not obj then
    log_warn("MemRec.GetOrCreateById(%02d) returned nil", mr.ID)
    return
  end
  obj:onPostExec(mr, newState, succeeded)
end


if (false) then
  --[[ NOT GOOD IDEA TO PLAY WITH THIS CB (Unless you want to invoke external editor for AA scripts)
    AddressList class:
      OnAutoAssemblerEdit: function(addresslist,memrec)
        - Called when the user initiates a memoryrecord AA script edit.
          This function will be responsible for changing the memory record

  local function OnAutoAssemblerEdit(al, mr)
    log_info("OnAutoAssemblerEdit mr[id = %04d]", mr.ID)
  end

  local function RegisterOnAutoAssemblerEditHanler()
    local al = getAddressList()
    al.OnAutoAssemblerEdit = OnAutoAssemblerEdit  
  end

  local function UnregisterOnAutoAssemblerEditHanler()
    local al = getAddressList()
    al.OnAutoAssemblerEdit = nil
  end
  --UnregisterOnAutoAssemblerEditHanler()
  --]]
end

----------------------------------------------------------------------------------
--                       S T A T I C   M E T H O D S
----------------------------------------------------------------------------------


function C.FindById(id)
  local c = GetCache()
  local obj = c.memrecs.byId[id]
  return obj
end


function C.GetOrCreateById(id)
  local al = getAddressList()
  local mr = al.getMemoryRecordByID(id)
  if not mr then log_err("no such mr (id = %03d)", id) end

  local c = GetCache()
  local byId = c.memrecs.byId
  local obj = byId[id]
  if obj then
    if obj.mr ~= mr then
      log_warn("mr (id = %03d) has been replaced", id)
      obj.mr = mr
    end
    return obj
  end
  
  local obj = C:New(mr)
  byId[id] = obj
  return obj
end


function C.GetCurrent()
  local c = GetCache()
  local mrs = c.memrecs
  local curId = mrs.curId
  local obj = curId and mrs.byId[curId] or nil
  return obj
end


function C.ClearCurrent()
  local obj = C.GetCurrent()
  if not obj then return nil end

  local c = GetCache()
  local mrs = c.memrecs
  mrs.curId = nil

  local desc = obj.mr.Description:match("^((%S+%s+){0,5}%S+)") or obj.mr.Description -- obj.mr.Description:match("^([^ ]+)")
  log_info("MR %s [id=%03d] is no longer being compiled", desc, obj.id)
  return obj
end

----------------------------------------------------------------------------------
--                    I N S T A N C E   M E T H O D S
----------------------------------------------------------------------------------

function C:ctor(mr)
  log_verbose("new mr (id = %03d) instance created", mr.id)
  self.mr = mr
  self.id = mr.id
  return self
end

function C:onPreExec(mr, newState)
  assert(mr.ID == self.id)
  if mr ~= self.mr then
    log_warn("self.mr (id = %03d) has been replaced (onPreExec)", self.id)
    self.mr = mr
  end
  if mr.Type == vtAutoAssembler then
    log_dbg("mr.Type: %s", mr.Type)
    self:makeCurrent()
  end

  -- call all registered preExec handlers
  OnEvent("preExec", self, self.mr)
end

function C:onPostExec(mr, newState, succeeded)
  assert(mr.ID == self.id)
  if mr ~= self.mr then
    log_warn("self.mr (id = %03d) has been replaced (onPostExec)", self.id)
    self.mr = mr
  end

  local cur = C.GetCurrent()
  if cur == self then
    C.ClearCurrent()
  else
    --log_warn("self.id (%03d) is not current (%s) (onPostExec)", self.id, curId)
  end
  if succeeded and not newState then
    -- the record was deactivated
    -- we should unregister its symbols and deallocate its memory
    self:onDeactivate(mr, newState, succeeded)
  end
end

function C:makeCurrent()
  assert(self.id)
  local c = GetCache()
  local mrs = c.memrecs
  mrs.curId = self.id

  local desc = self.mr.Description:match("^((%S+%s+){0,5}%S+)") or self.mr.Description -- self.mr.Description:match("^([^ ]+)")
  log_info("MR %s [id=%03d] is currently being compiled", desc, self.id)
end

function C:getSymPrefix(arg)
  return self.symPrefix
end

function C:setSymPrefix(arg)
  self.symPrefix = (arg and #arg > 0) and arg or nil
end

function C:alloc(size)
  if not size then size = 0x10000 end
  local mbs = self.memBlocks
  if not mbs then
    mbs = {}
    self.memBlocks = mbs
  end

  -- allocateMemory(size, BaseAddress OPTIONAL, Protection OPTIONAL): Allocates some memory into the target process
  -- deAlloc(address, size OPTIONAL): Frees allocated memory
  local addr = allocateMemory(size)
  mbs[#mbs+1] = { addr, size }
  return addr
end

function C:registerSymbols(syms)
  if self.symPrefix then
    syms = table.deepcopy(syms)
    for _, s in ipairs(syms) do
      s[1] = self.symPrefix .. s[1]
    end
  end

  for _, s in ipairs(syms) do
    local sym, addr = s[1], s[2]
    log_verbose("  %-20s: 0x%012X", sym, addr)
    registerSymbol(sym, addr, true)
  end

  if self.syms then
    -- local function merge(t, from, overwrite, copy_tables)
    table.merge(self.syms, syms, true, false)
  else
    self.syms = syms
  end
end

-- the record may have been deactivated
-- we should unregister its symbols and deallocate its memory
function C:onDeactivate(mr, newState, succeeded)
  if mr.Type == vtAutoAssembler then
    local desc = mr.Description:match("^((%S+%s+){0,5}%S+)") or mr.Description -- mr.Description:match("^([^ ]+)")
    log_info("MR %s [id=%03d] deactivated", desc, self.id)
  
    if self.syms then
      for i, s in ipairs(self.syms) do
        unregisterSymbol(s[1])
      end
    end
    self.syms = nil

    if self.memBlocks then
      for i, mb in ipairs(self.memBlocks) do
        deAlloc(mb[1], mb[2])
      end
    end
    self.memBlocks = nil
  end
end

return C
