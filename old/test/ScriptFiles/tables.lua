-- tables.lua --
local tables = {}

function table.find_first_where(t, fcond, ...)
  for k, v in ipairs(t) do
    if fcond(k, v, ...) then
      return k, v
    end
  end
end

function table.remove_where(t, fcond, ...)
  local gap, len = 0, #t
   for i = 1, len do
    local v = t[i]
    if v == nil or fcond(i, v, ...) then -- we have to remove this element
      t[i] = nil
      gap = gap + 1
    elseif gap > 0 then -- we have to keep this element, but on different position as there is a gap
      t[i - gap] = v
      t[i] = nil
    end
  end
end
tables.remove_where = table.remove_where


function table.try_nest(root, path, do_not_create)
  local node = root
  for _, name in ipairs(path) do
    local child = node[name]
    if not child then
       if do_not_create then return nil end
       child = {}
       node[name] = child
    end
    node = child
  end
  return node
end
tables.try_nest = table.try_nest


function table.array_to_set(a)
  if not a then return nil end
  local s = {}
  for i, v in ipairs(a) do s[v] = true end
  return s
end
tables.array_to_set = table.array_to_set


function table.compare(t1, t2)
  if t1 == t2 then return true end
  for k, v in pairs(t1) do
    if type(v) == "table" and type(t2[k]) == "table" then
       if not table.compare(v, t2[k])   then return false end
    else
       if (v ~= t2[k]) then return false end
    end
  end
  for k, v in pairs(t2) do
    if t1[k] == nil then return false end
  end
  return true
end
tables.compare = table.compare


local deepcopy
deepcopy = function(object)
  local lookup_table = {}
  local function _copy(object)
    if type(object) ~= "table" then
      return object
    else
      if lookup_table[object] then
        return lookup_table[object]
      end
    end
    local new_table = {}
    lookup_table[object] = new_table
    for index, value in pairs(object) do
      new_table[_copy(index)] = _copy(value)
    end
    return setmetatable(new_table, getmetatable(object))
  end
  return _copy(object)
end
tables.deepcopy = deepcopy
table.deepcopy = deepcopy


-- simple top-level table merge
local function merge(t, from, overwrite, copy_tables)
  for k, v in pairs(from) do
    if not t[k] or overwrite then
      if copy_tables and (type(v) == "table") then
        t[k] = deepcopy(v)
      else
        t[k] = v
      end
    end
  end
end
tables.merge = merge
table.merge = merge

-- merges and/or deep-copies tables recursively.
-- overwrite: if true, entries in from table override entries in t, unless
--   both entries are tables, in which case they are recursively merged.
-- copy_tables: if true, then tables that are not merged are deep-copied
local deepmerge
deepmerge = function(t, from, overwrite, copy_tables)
  for k, v in pairs(from) do
    if (type(v) == "table") then
      if (type(t[k]) == "table") then
        t[k] = deepmerge(t[k], v, overwrite, copy_tables)
      elseif overwrite or (t[k] == nil) then
        if copy_tables then
          t[k] = deepcopy(v)
        else
          t[k] = v
        end
      end
    elseif overwrite or (t[k] == nil) then
      t[k] = v
    end
  end
  return t
end
tables.deepmerge = deepmerge
table.deepmerge = deepmerge


local remove = table.remove
-- removes first occurence of value in the table (array)
-- returns true if it found such a value
table.remove_value = function(t, value)
  for k, v in pairs (t) do
    if v == value then
      remove(t, k)
      return true
    end
  end
  return false
end
tables.remove_value = table.remove_value


return tables
