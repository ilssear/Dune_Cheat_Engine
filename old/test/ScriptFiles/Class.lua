-- Class.lua --

local instances_mode = "v"

local next_instance_id = 1

local format = string.format
local tables = require "tables"

local C = {
  cls_name = "Class",
  is_abstract = true,
  cls_mt = {},
  --obj_mt = {}, -- missing as it is abstract class
}
setmetatable(C, C.cls_mt) --  so that it is recognized as a class

-- global store for classes and their static tables (i.e. instances)
-- this is designed to survive hot reload of all *.lua files
_G.Classes = _G.Classes or {
  static = {},
  by_name = {
    Class = C,
  },
  list = {
    C,
  }
}
local Classes = _G.Classes
C.Classes = Classes



local function IsClass(cls)
  return (type(cls) == "table") and getmetatable(cls) and (rawget(cls, "cls_mt") == getmetatable(cls))
end
C.IsClass = IsClass

local function CheckClass(cls, arg_name)
  if not IsClass(cls) then errn(3, "%s: %s (%s) has to be a class", arg_name or "self", cls, type(cls)) end
end
C.CheckClass = CheckClass


local function IsInstance(obj)
  local is_obj, cls
  if (type(obj) == "table") then
    local mt = getmetatable(obj)
    if mt then
      cls = mt.cls
      is_obj = cls and (cls.obj_mt == mt)
    elseif obj.__cls_name then
      cls = Classes.by_name[obj.__cls_name]
      if cls then
        setmetatable(obj, cls.obj_mt)
        is_obj = true
      end
    end
  end
  return is_obj, is_obj and cls or nil
end
C.IsInstance = IsInstance

local function CheckInstance(obj, arg_name)
  local is_obj, cls = IsInstance(obj)
  if not is_obj then errn(3, "%s: %s (%s) has to be an instaance", arg_name or "self", obj, type(obj)) end
  return cls
end
C.CheckInstance = CheckInstance

function C:Subclass(cls_name, cctor, ...)
  local base = self
  if not IsClass(base) then errn(2, "<CLASS>:Subclass() missing arg0 (base)") end
  if type(cls_name) ~= "string" then errn(2, "%s:Subclass() arg1 (cls_name) is %s, expected string", base.cls_name, type(cls_name)) end

  local static, hasOldInstances = Classes.static[cls_name], false
  if not static then
    static = {
      instances = {}
    }
    Classes.static[cls_name] = static
  else
    hasOldInstances = true
  end

  local instances_mt = { __mode = instances_mode or "v" }
  static.instances_mt = instances_mt
  setmetatable(static.instances, instances_mt)

  local cls = {
    cls_name = cls_name,
    static = static,
    base = base,
    cctor = cctor,
    --is_abstract = true,
    cls_mt = {
        base = base,
        __index = base,
    },
    obj_mt = {
        cls_name = cls_name,
        __gc = C.DestroyByGC,
    },
  }
  cls.cls = cls
  setmetatable(cls, cls.cls_mt)

  cls.obj_mt.cls = cls
  cls.obj_mt.__index = cls

  local cls_list = Classes.list
  local cls_idx, old_cls = table.find_first_where(cls_list,
      function (_, c, cn) return (c.cls_name == cn) end,
      cls_name)
  cls_list[cls_idx or (#cls_list + 1)] = cls
  Classes.by_name[cls_name] = cls

  if type(cctor) == "function" then
    cls:cctor(...)
  elseif type(cctor) == "table" then
    tables.deepmerge(cls, cctor, true)
  end

  if hasOldInstances then
    cls:ReaquireOldInstances()
  end

  return cls
end

local function __vf__index(obj, k)
  local cls = CheckInstance(obj)

  -- try to find the corresponding getter in this class and bases
  -- cls.__get may have a metatable for serching in bases
  local getters = rawget(cls, "__get")
  local getter = getters and getters[k] or nil
  if getter then return getter(obj, k) end

  -- if there is no getter, it may be class level field/function
  local res = cls[k] -- get field in the class hierarchy
  if res then return res end

  -- we don't have getter nor the class level field, give up
  return nil
end

local function __vf__newindex(obj, k, v)
  local cls = CheckInstance(obj)

  -- try to find the corresponding setter in this class abd bases
  -- cls.__set may have a metatable for serching in bases
  local setters = rawget(cls, "__set")
  local setter = setters and setters[k] or nil
  if setter then setter(obj, k, v) end

  -- if there is no setter, we have to create a normal field
  rawset(obj, k, v)
end

function C:AddVirtualFieldSupport(__index, __newindex)
  CheckClass(self)
  if not __index then __index = __vf__index end
  if not __newindex then __newindex = __vf__newindex end

  local get, set = {}, {}
  self.__get, self.__set = get, set

  local base = self.base

  if (base.__get) then
    local get_mt = { cls = self, __index = base.__get }
    self.__get_mt = get_mt
    setmetatable(get, get_mt)
  end

  if (base.__set) then
    local set_mt = { cls = self, __index = base.__set }
    self.__set_mt = set_mt
    setmetatable(set, set_mt)
  end

  self.obj_mt.__index = __index
  self.obj_mt.__newindex = __newindex

  return get, set
end

function C:ReaquireOldInstances()
  local instances = self.static.instances
  local nInstances = 0
  for k, v in pairs(instances) do
    self:AcquireInstance(v)
    nInstances = nInstances + 1
  end
  if nInstances > 0 then
    dbg("%s:ReaquireOldInstances(): %d", self.cls_name, nInstances)
  end
end

function C:AcquireInstance(obj, force)
  if not IsClass(self) then errn(2, "Must be called on class") end
  if type(obj) ~= "table" then errn(2, "arg1 obj: %s (%s) not a table", obj, type(obj)) end

  local obj_mt, cls_name = rawget(self, "obj_mt"), rawget(self, "cls_name")
  if (not obj_mt) or (not cls_name) then errn(2, "self is not a class. obj_mt: %s, cls_name: %s", obj_mt, cls_name) end

  if (not force) and obj.__cls_name and (obj.__cls_name ~= cls_name) then
    errn("Class %s can't acquire instance of type %s", self.cls_name, obj.__cls_name)
  end

  obj.__cls_name = cls_name

  -- if class supports virtual fields and table for them is missing, add it to the object
  if self.__get and (not rawget(obj, "__vf")) then rawset(obj, "__vf", {}) end
  setmetatable(obj, self.obj_mt)
end


function C:New(...)
  local cls = self
  if not IsClass(cls) then errn(2, "Class:New(...) arg0 cls (%s) is not a class", type(cls)) end
  if rawget(cls, "is_abstract") then errn(2, "Class:New(...) arg0 cls (%s) is marked as abstract") end

  local obj = {
    __cls_name = cls.cls_name,
    __vf = (cls.__get) and {} or nil, -- table for virtual fields in the object
  }
  setmetatable(obj, cls.obj_mt)
  obj:ctor(...)
  return obj
end

function C:Destroy(reason, ...)
  local obj = self
  local is_obj, cls = IsInstance(obj)
  if not is_obj then errn(2, "<OBJ>:Destroy(...) arg0, obj (%s) is not an instance", type(obj)) end

  local id = obj.__id
  obj:dtor(reason, ...)
  if id and (reason ~= "GC") then obj:UnregisterInstance() end

  obj.__cls_name = nil
  setmetatable(obj, nil)

  return id
end

function C:DestroyByGC()
  if not self.static.__gc_silent then
    printf("C:DestroyByGC(%s)", self)
    printf("WARN: Instance %s of cls %s collected by GC before its :Destroy() was called.", self.__id or "", self.cls_name)
  end
  self:Destroy("GC")
end


function C:DestroyInstances(reason)
  if not IsClass(self) then errn(2, "Must be called on class") end
  local instances = self.static.instances
  if not reason then reason = self.cls_name .. ":DestroyInstances" end
  for i = 1, 100000 do
    local k, v = next(instances)
    if not v then break end
    if i < 100 then
      printf("%s:DestroyInstances(%s): %s", self.cls_name, reason, k)
    elseif i == 100 then
      print(" ... and more")
    end
    v:Destroy(reason)
  end
end


local allowed_instance_id_types = {
  string = true,
  number = true,
}

function C:RegisterInstance(id, replace)
  local obj = self
  local is_obj, cls = IsInstance(obj)
  if not is_obj then errn(2, "<OBJ>:RegisterInstance() arg0 (self, obj) got %s, expected an instance", cls, type(obj)) end
  local instances = cls.static.instances
  if id then
    if not allowed_instance_id_types[type(id)] then errn(2, "%s:RegisterInstance() arg1 (id) got %s, expected id", cls, type(id)) end
    if (not replace) and instances[id] then
      printf("WARN: Instance %s of cls %s is already registered and will be replaced by a new one", id, cls.cls_name)
    end
  else
    while(instances[next_instance_id]) do next_instance_id = next_instance_id + 1 end
    id = next_instance_id
    next_instance_id = next_instance_id + 1
  end
  obj.__id = id
  instances[id] = obj
  return id
end

function C:FindInstance(id, no_err, silent)
  local cls = self
  if not IsClass(cls) then errn(2, "<class>:FindInstance(id) arg0 self cls (%s) is not a class", type(cls)) end

  if not id then
    local msg = format("%s:FindInstance(id) id is nil", cls.cls_name)
    if no_err then
      printf("ERR: %s", msg)
    else
      errn(2, msg)
    end
  end

  local instances = cls.static.instances
  local obj = instances[id]
  if not obj then
    local msg = format("%s:FindInstance(id) instance with this id (%s) is not registered", cls.cls_name, id)
    if no_err then
      if not silent then printf("WRN: %s", msg) end
    else
      errn(2, msg)
    end
  end
  return obj
end

function C:UnregisterInstance(no_err, silent)
  local obj = self
  local is_obj, cls = IsInstance(obj)
  if not is_obj then errn(2, "<OBJ>:UnregisterInstance() arg0 (self, obj) got %s, expected an instance", cls, type(obj)) end

  local id = obj.__id
  if not id then
    local msg = format("%s:UnregisterInstance() instance is not registered (no __id is set)", cls.cls_name)
    if no_err then
      if not silent then printf("WRN: %s", msg) end
    else
      errn(2, msg)
    end
  end

  obj.__id = nil

  local instances = cls.static.instances
  if instances[id] == obj then
    instances[id] = nil
  elseif instances[id] then
    printf("WARN: %s:UnregisterInstance(): Instance %s was replaced by another one while registered", cls.cls_name, id)
  else
    printf("WARN: %s:UnregisterInstance(): Instance %s was removed from instances table while registered", cls.cls_name, id)
  end
  --print(debug.traceback())
end

function C:ctor()
end

function C:dtor(reason, ...)
end

return C
