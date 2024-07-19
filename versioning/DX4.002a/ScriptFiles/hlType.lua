-- hlType.lua
-- Collects hashlink runtime types


local thisClsName = "hlType"

local Base = require "Class"


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


local U = require("util".."")
--local MR = require("MemRec".."")
local CU = require("c_util".."")



-- hl type kinds for x64 architecture
local hl_type_kind_traits = {
  -- kind id  name     size  align  c-type
	{       1, "HUI8",      1,     1, "byte"   },
	{       2, "HUI16",     2,     2, "ushort" },
	{       3, "HI32",      4,     4, "int"    },
	{       4, "HI64",      8,     8, "int64"  },
	{       5, "HF32",      4,     4, "float"  },
	{       6, "HF64",      8,     8, "double" },
	{       7, "HBOOL",     1,     1, "bool"   },
	{       8, "HBYTES",    8,     8, "byte*"  },
	{       9, "HDYN",      8,     8, "void*"  },
	{      10, "HFUN",      8,     8, "void*"  },
	{      11, "HOBJ",      8,     8, "byte*"  },
	{      12, "HARRAY",    8,     8, "void*"  },
	{      13, "HTYPE",     8,     8, "void*"  },
	{      14, "HREF",      8,     8, "void*"  },
	{      15, "HVIRTUAL",  8,     8, "void*"  },
	{      16, "HDYNOBJ",   8,     8, "void*"  },
	{      17, "HABSTRACT", 8,     8, "void*"  },
  {      18, "HENUM",     8,     8, "void*"  },
	{      19, "HNULL",     8,     8, "void*"  },
	{      20, "HMETHOD",   8,     8, "void*"  },
	{      21, "HSTRUCT",   8,     8, "byte*"  },
	{      22, "HPACKED",   8,     8, "void*"  },
	[0] = { 0, "HVOID",     0,     0, "void"   },
	---------
	HLAST     = 23,
	--_H_FORCE_INT = 0x7FFFFFFF
}

hl_max_type_kind = hl_type_kind_traits.HLAST - 1
hl_max_basic_type_kind = 7
-- enum hl_type_kind
hl_type_kind = {}
-- lookup tables for hl_type_kind (number to name, size or align)
hl_type_kind_name = {}
hl_type_kind_size = {}
hl_type_kind_align = {}
hl_type_kind_c_type = {}
for i = 0, hl_max_type_kind do
  local id, name, size, align, ct = unpack(hl_type_kind_traits[i])
  hl_type_kind[name] = id
  hl_type_kind_name[i] = name
  hl_type_kind_size[i] = size
  hl_type_kind_align[i] = align
  hl_type_kind_c_type[i] = ct
end

-- virtual memory region types
MEM_PRIVATE = 0x00020000
MEM_IMAGE   = 0x01000000
MEM_MAPPED  = 0x00040000

-- virtual memory region allocation status constants
MEM_COMMIT      = 0x00001000
MEM_RESERVE     = 0x00002000
MEM_RESET       = 0x00080000
MEM_RESET_UNDO  = 0x1000000
MEM_LARGE_PAGES = 0x20000000
MEM_PHYSICAL    = 0x00400000
MEM_TOP_DOWN    = 0x00100000
MEM_WRITE_WATCH = 0x00200000


-- virtual memory protection constants ( https://docs.microsoft.com/en-us/windows/win32/Memory/memory-protection-constants )
PAGE_NOACCESS  = 0x01
PAGE_READONLY  = 0x02
PAGE_READWRITE = 0x04
PAGE_WRITECOPY = 0x08

PAGE_EXECUTE           = 0x10
PAGE_EXECUTE_READ      = 0x20
PAGE_EXECUTE_READWRITE = 0x40
PAGE_EXECUTE_WRITECOPY = 0x80

PAGE_TARGETS_INVALID   = 0x40000000
PAGE_TARGETS_NO_UPDATE = 0x40000000

-- The following are modifiers that can be used in addition to the options provided in the previous table, except as noted.
PAGE_GUARD = 0x100
PAGE_NOCACHE = 0x200
PAGE_WRITECOMBINE = 0x400

local _hlCache = nil
local function GetCache(forceClear)
  local pid = getOpenedProcessID()
  if (not pid or (pid == 0)) and not forceClear then
    errn(2, "Game process not opened")
  end

  if not _hlCache or (_hlCache.pid ~= pid) or forceClear then
    _hlCache = {
      pid = pid, -- pid of the game
      types = { -- type cache
        pid = nil, -- pid of the game (managed by C.FindMainTypeArray())
        pBegin = nil, -- where the hl_type array begins
        pEnd = nil, -- end of the hl_type array
        count = nil, -- # of hl_type items
        short = nil, -- array of short types, then lookups by_pType and by_name tables of cached types (short versions)
        full = nil, -- by_pType and by_name tables of cached types (full versions)
      },
      c_gen = nil, -- C code generator cache
    }
    --C._hlCache = _hlCache
  end
  return _hlCache, pid
end
GetCache(true)
C.GetCache = GetCache


local minTypesRegionSize = 0x100000
local minTypesOffset = 0x0040;
local maxTypesOffset = 0x0180;

function C.FindMainTypeArray()
  local hlc, pid = GetCache()
  local tc = hlc.types

  local cCache = CU.GetCache()
  local isDev = cCache.isDev

  if (tc.pid == pid) then
    return tc.pBegin, tc.pEnd, tc.short.array
  end

  -- we don't have the types cached (yet)
  -- try to find the types by LUA way
  local pBegin = C.FindTypesBeginLUA()
  if pBegin then
    printf("LUA found the hlTypesBegin: 0x%012X", pBegin)
  end
  if not pBegin or isDev then
    -- the simple LUA way failed to find the types array,
    -- we should try to find it the harder C way
    pBegin = C.FindTypesBeginC()
    if pBegin then
      printf("C found the hlTypesBegin: 0x%012X", pBegin)
    else
      -- we have a fatal problem - without types, we can't do anything
      err("\n\nFATAL: Main game metadata (type array) not found\n\n")
    end
  end

  local tar, pEnd = C.CollectShortTypesFrom(pBegin)
  C.CacheShortTypes(tar, pBegin, pEnd)
  tc.pid = pid
  return pBegin, pEnd, tar
end


-- the easier way of finding the types array begin
function C.FindTypesBeginLUA()
  -- enumMemoryRegions() : Returns an indexed table containing the memorylayout.
  --   Each entry consists out of: BaseAddress, AllocationBase, AllocationProtect, RegionSize, State, Protect, Type
  local all_regions = enumMemoryRegions()
  --printf("regions = %s", serpent.block(regions))
  if not all_regions then return false, "No memory regions" end
  printf("found %s memory regions", all_regions and #all_regions or nil)

  -- walk through regions and examine them for type array presence
  for i, r in ipairs(all_regions) do
    --printf("R: 0x%012X, S: 0x%08X", r.BaseAddress, r.RegionSize)
    if r.State == MEM_COMMIT and
       --r.BaseAddress == r.AllocationBase and
       r.AllocationProtect == PAGE_READWRITE and
       r.Protect == PAGE_READWRITE and
       -- r.RegionSize >= minTypesRegionSize and
       true then
      -- we have region with right properties

      -- lets examine its contents
      local pBegin, pBeginMsg = C.FindTypesBeginInRegion(r)
      if pBegin then return pBegin end
    end
  end
end

function C.FindTypesBeginInRegion(r)
  --[[ ------------------------------------------------------
       we have found a candidate region with right properties
       so we can scan for type definition array
       - each type takes 0x20 bytes
       - and those at te beginning look like (in 8 byte integers):
           0, 0, 0, 0,
           1, 0, 0, 0,
           2, 0, 0, 0,
           3, 0, 0, 0,
           4, 0, 0, 0,
           5, 0, 0, 0,
           6, 0, 0, 0,

       - alligned at 8 bytes
       - this pattern seems to be unique in the whole process
       - and we also know that so far it always begat at
           mbi.AllocationBase + 0x00000098

       - but we should probably give it some tolerance
       ------------------------------------------------------
       Group Scan Command:
         BA:8 8:0 8:0 8:0 8:0 8:1 8:0 8:0 8:0 8:2 8:0 8:0 8:0 8:3 8:0 8:0 8:0 8:4 8:0 8:0 8:0 8:5 8:0 8:0 8:0 8:6 8:0 8:0 8:0 
       ------------------------------------------------------
  --]]
  -- simple (not optimized) pattern scan
  local ba = r.BaseAddress
  -- count the leading zero qwords
  local nZeros = 0
  local v = -1
  local a = ba + minTypesOffset
  while (a <= (ba + maxTypesOffset)) do
    v = readPointer(a)
    a = a + 8
    if (v == 0) then
      nZeros = nZeros + 1
    else
      if (nZeros >= 4) and (v == 1) then
        break;
      end
      nZeros = 0;
    end
  end

  -- we exited the first loop (counting leading zeros)
  -- if the nZeros < 4 or v != 1 then we failed and can try another region
  if ((nZeros < 4) or (v ~= 1)) then
    return nil, "not leading zeros followed by one" -- not the type array we are searching for
  end

  -- this loop will count the non-zero qwords from 1 to 6 (see the pattern above)
  local maxNZ = 6
  for i = 1, maxNZ do
    -- check the non-zero qword (it must be v == i)
    if (v ~= i) then return nil, format("v != i (%s, %s)", v, i) end
    -- there must be exactly 3 zeros
    for j = 1, 3 do
      v = readPointer(a)
      a = a + 8
      if v ~= 0 then return nil, format("v[%s] != 0 (%s)", j, v) end
    end
    -- read another qword for the next loop
    v = readPointer(a)
    a = a + 8
  end
  
  -- we finished the scan loop
  -- so we have found the pattern of the beginning of type array
  -- move the pointer back before the pattern to real array begin
  local pBegin = a - (1 + (maxNZ + 1) * 4) * 8;
  return pBegin;
end


-- the harder way of finding the types array begin
function C.FindTypesBeginC()
  local allocSize = 0x10000
  local addr = allocateMemory(allocSize)
  if not addr then err("Can't allocate 0x%X bytes in the target process", allocSize) end

  local cFileName = "FindTypes.c"
  local syms, msg, c_syms = CU.CompileCFiles({ cFileName }, true, addr)
  if not syms then err("Can't compile %s: %s", cFileName, msg) end

  local fnName, resName = "hlFindTypes", "hlFindTypes_Result"
  local fnAddr, resAddr = c_syms[fnName], c_syms[resName]
  if not fnAddr then
    printf("Can't retrieve symbol %s from compiled file %s", fnName, cFileName)
    return nil
  end
  if not resAddr then printf("Can't retrieve symbol %s from compiled file %s", resName, cFileName) end

  registerSymbol(fnName, fnAddr, true)
  registerSymbol(resName, resAddr, true)

  printf("Executing %s (0x%012X)", fnName, fnAddr)
  local res = executeCode(fnAddr, 0, 30 * 1000)
  printf("Returned from %s with result: 0x%012X", fnName, res or 0)
  if res > 0x10000 and (res < 0x7FFF00000000) then
    local r = {
      pBegin = readPointer(res + 0x00),
      pBaseAddr = readPointer(res + 0x08),
      pAllocAddr = readPointer(res + 0x10),
      nRegionsScanned = readPointer(res + 0x18),
      nScans = readPointer(res + 0x20),
      nQwTotal = readPointer(res + 0x28),
      pErrRegionBase = readPointer(res + 0x30),
      errCode = readInteger(res + 0x38),
    }
    if r.pBegin and (r.pBegin > 0) then
      registerSymbol("hlTypesBegin", r.pBegin)
      printf("registerSymbol(\"hlTypesBegin\", 0x%012X)", r.pBegin)
    end
    printf("%s = %s", resName, serpent.block(r, { numformat = "0x%012X" }))
    return r.pBegin
  else
    print("%s (%s) failed to find type definitions: %s", fnName, cFileName, res)
  end
end


-- walk through the type array and collect the basic info about types
function C.CollectShortTypesFrom(pBegin)
  local tar = {} -- our array of short types
  local pType = nil
  local maxCount = 1000000
  for ti = 1, maxCount do
    pType = pBegin + (ti - 1) * 0x20 -- 0x20 is stride of hl_type
    local ok, t, msg = xpcall(C.ParseShortType, xerrp, pType)
    if ok and t then
      tar[ti] = t
    else
      if not ok then msg = t end
      -- err? we have probably reached the end of the hl_type array
      printf("collected %d types\n - end of the hl_type array at 0x%012X reached: (%s)", #tar, pType, msg)
      return tar, pType, #tar
    end
  end
  printf("WARNING! NOT reached the end of the hl_type array after %d items", maxCount)
  return tar, pType, #tar
end

-- get basic info about one type in the type array
function C.ParseShortType(pType)
  local kind, kind_name = C.ParseTypeKind(pType)
  if not kind then return nil, kind_name end -- kind_name should contain err msg

  local pParamT, param_type, msg = nil, nil, nil
  local pSuper
  if (kind == hl_type_kind.HNULL) or (kind == hl_type_kind.HREF) or (kind == hl_type_kind.HPACKED) then
    -- read the type parameter
    pParamT, msg = readPointer(pType + 0x08)
    if not pParamT then return nil, msg .. "inaccessible hl_type.tparam" end

    param_type, msg = C.ParseShortType(pParamT)
    if not param_type then return nil, msg .. " (param_type)" end
  elseif (kind == hl_type_kind.HOBJ) or (kind == hl_type_kind.HSTRUCT) then
    -- get hl_type_obj *obj
    local tobj = readPointer(pType + 0x08)
    -- base class (super)
    pSuper = readPointer(tobj + 0x18)
  end

  return {
    kind = kind,
    kind_name = kind_name,
    name = C.ParseTypeName(pType),
    param_type = param_type,
    pType = pType,
    pSuperType = (pSuper and (pSuper > 0)) and pSuper or nil,
  }
end

-- write the basic info about the types into cache
-- sorted by name and by pointer to make type resolving easier
function C.CacheShortTypes(tar, pBegin, pEnd)
  local by_pType, by_name = {}, {}
  local num = #tar
  for i = 1, num do
    local t = tar[i]
    if t.pType then by_pType[t.pType] = t end
    if t.name then
      local t2 = by_name[t.name]
      if not t2 then
        by_name[t.name] = t
      else
        -- oops, there is name conflict
        --   i.e. two "String" types: one HOBJ and one HENUM
        if t.kind == hl_type_kind.HOBJ then
          by_name[t.name] = t
        elseif t2.kind == hl_type_kind.HENUM then
          by_name[t.name] = t
        end

        -- store them both with kind suffix: "<name> (<kindname>)"
        local tn = format("%s (%s)", t.name, t.kind_name)
        local t2n = format("%s (%s)", t2.name, t2.kind_name)
        by_name[tn] = t
        by_name[t2n] = t2
      end
    end
  end
  
  local hlc = GetCache()
  local tc = hlc.types
  tc.pBegin = pBegin
  tc.pEnd = pEnd
  tc.count = num

  tc.short = {
    array = tar,
    by_pType = by_pType,
    by_name = by_name,
  }
  
  -- connect classes with their base classes
  for i = 1, num do
    local t = tar[i]
    local pSuper = t.pSuperType
    if pSuper then
      local s = by_pType[pSuper]
      t.super_type = s;
      if not s then printf("WRN: super (0x%012X) not found for %s: %s (0x%012X)", pSuper, t.kind_name, t.name, t.pType) end
    end
  end

end




function C.ParseType(pType)
  local kind, msg = C.ParseTypeKind(pType)
  if not kind then errn(2, msg) end
  
  -- if kind is ok, the 2nd ret contains kind name
  local kind_name = msg

  local t
  if (kind > hl_max_basic_type_kind) then
    -- object types have their own parser
    if kind == hl_type_kind.HFUN then
      t = C.ParseFunType(kind, kind_name, pType)
      return t
    elseif kind == hl_type_kind.HOBJ or kind == hl_type_kind.STRUCT then
      t = C.ParseObjType(kind, kind_name, pType)
      return t
    elseif kind == hl_type_kind.HVIRTUAL then
      t = C.ParseVirtualType(kind, kind_name, pType)
      return t
    end
  end

  -- basic type descriptor
  t = {
    kind = kind,
    kind_name = kind_name,
    size = hl_type_kind_size[kind],
    align = hl_type_kind_align[kind],
    name = C.ParseTypeName(pType),
  }
  if (kind <= hl_max_basic_type_kind) then
    -- basic types don't need anythind else
    return t
  end

  if kind == hl_type_kind.HENUM then
    t.options = C.ParseEnumOptions(pType)
  end
  return t
end

function C.ParseTypeKind(pType)
  if type(pType) ~= "number" or pType == 0 then
    return nil, format("Invalid pType (arg 1 to %s.GetObjTypeFields): %s", thisClsName, pType)
  end
  -- hl_type_kind kind must be HOBJ
  local kind = readInteger(pType + 0x00)
  if not kind then
    return nil, "pType->kind inaccessible"
  end
  if (kind < 0) or (kind > hl_max_type_kind) then
    return nil, format("Invalid hl_type.kind (0x%08X)", kind)
  end

  local kind_name = hl_type_kind_name[kind]
  return kind, kind_name
end

function C.ParseTypeName(pType)
  local kind = readInteger(pType)
  local pSpecType = readPointer(pType + 0x08)
  local pName = nil
  if kind == hl_type_kind.HOBJ or kind == hl_type_kind.HSTRUCT then
    pName = readPointer(pSpecType + 0x10)
  elseif kind == hl_type_kind.HENUM then
    pName = readPointer(pSpecType + 0x00)
  elseif kind == hl_type_kind.HABSTRACT then
    pName = pSpecType
  end
  if pName then
    return readString(pName, 1024, true)
  end
  return nil
end

function C.ParseEnumOptions(pType)
  local tenum = readPointer(pType + 0x08)
  local nopts, pOpts = readInteger(tenum + 0x08), readPointer(tenum + 0x10)
  local opts = {}
  for i = 0, nopts - 1 do
    local pOpt = pOpts + i * 0x28 -- sizeof(hl_enum_construct)
    local pName = readPointer(pOpt + 0x00)
    local o = {
      index = i,
      name = readString(pName, 1024, true),
      nparams = readInteger(pOpt + 0x08),
      pParams = readPointer(pOpt + 0x10),
      size = readInteger(pOpt + 0x18),
      hasptr = (readByte(pOpt + 0x1C) ~= 0),
      offsets = readInteger(pOpt + 0x20),
    }
    opts[i+1] = o
  end
  return opts
end

function C.ParseObjType(kind, kind_name, pType)
  local th = C.ParseObjTypeInheritanceNested(kind, kind_name, pType)
  local t = C.FlattenObjTypeInheritance(th)
  C.ParseObjTypeFields(t)
  C.ParseObjTypeMethods(t)
  return t
end

function C.ParseObjTypeInheritanceNested(kind, kind_name, pType)
  if kind ~= hl_type_kind.HOBJ then
    errn(2, "Type kind is not HOBJ (0x%02X), but %s (0x02X)", hl_type_kind.HOBJ, hl_type_kind_names[kind], kind)
  end

  -- get hl_type_obj *obj
  local tobj = readPointer(pType + 0x08)
  local nfields, nproto, nbindings = readInteger(tobj + 0x00), readInteger(tobj + 0x04), readInteger(tobj + 0x08)
  
  local pName = readPointer(tobj + 0x10)
  local name = readString(pName, 1024, true)
  if type(name) ~= "string" then
    errn(2, "Unable to read hl_type_obj->name")
  end
  
  local pSuper = readPointer(tobj + 0x18)
  local super
  if pSuper > 0 then
    local k, kn = C.ParseTypeKind(pSuper)
    super = C.ParseObjTypeInheritanceNested(k, kn, pSuper)
  end

  local pFields, pProto, pBindings = readPointer(tobj + 0x20), readPointer(tobj + 0x28), readPointer(tobj + 0x30)
  local ppGlobalValue, pModuleCtx, pRuntimeObj = readPointer(tobj + 0x38), readPointer(tobj + 0x40), readPointer(tobj + 0x48)

  local res = {
    kind = kind,
    kind_name = kind_name,
    pType = pType,
    nfields = nfields,
    nproto = nproto,
    nbindings = nbindings,
    name = name,
    super = super,
    pFields = pFields,
    pProto = pProto,
    pBindings = pBindings,
    ppGlobalValue = ppGlobalValue,
    pModuleCtx = pModuleCtx,
    pRuntimeObj = pRuntimeObj,
  }

  return res
end

function C.FlattenObjTypeInheritance(th)
  local function FlattenRecusive(th)
    local super = th.super
    local res
    if super then
      res = FlattenRecusive(super)
      --th.super = nil
      res[#res+1] = th
    else
      res = { th }
    end
    return res
  end

  local res = FlattenRecusive(th)
  return res
end

-- parse field info for whole flat object hierarchy
function C.ParseObjTypeFields(t)
  for i, s in ipairs(t) do
    -- parse fields only if they are not already there
    if not s.fields then
      C.ParseObjSubTypeFields(s)
    end
  end
end

-- parse field info of (top) object type level
-- super.fields must be already populated
function C.ParseObjSubTypeFields(t)
  local super = t.super
  local offset = super
    and super.fields.total_size
    or 0x8 -- the first field is always pType (x64)
  local fields = {
    begin_offset = offset,
    super_fields = super and super.fields or nil,
  }
  t.fields = fields

  local nfields, pField = t.nfields, t.pFields
  for i = 1, nfields do
    local field = C.ParseObjTypeField(t, i, offset, pField)
    fields[i] = field
    offset = field.offset + field.size
    pField = pField + 0x18 -- sizeof(hl_obj_field) == 0x14, but struct align = 8, so stride = 0x18
  end
  fields.total_size = offset

  return fields
end

-- parse field info of one particular field at given offset
function C.ParseObjTypeField(t, i, offset, pField)
  local pName = readPointer(pField + 0x00)
  local pType = readPointer(pField + 0x08)
  local kind, msg = C.ParseTypeKind(pType)
  if not kind then
    errn(4, msg)
  end
  local kind_name = msg
  local field_offset, pad = C.AlignOffsetForKind(offset, kind)
  local f = {
    kind = kind,
    kind_name = kind_name,
    name = readString(pName, 1024, true),
    hashed_name = readInteger(pField + 0x10),
    offset = field_offset,
    padding = pad,
    size = hl_type_kind_size[kind],
    pField = pField,
    pType = pType,
    type_name = C.ParseTypeName(pType),
    pObjType = t.pType,
  }
  return f
end

function C.AlignOffsetForKind(offset, kind)
  local align = hl_type_kind_align[kind]
  return C.AlignOffset(offset, align)
end

function C.AlignOffset(offset, align)
  local mod = offset % align
  if mod == 0 then
    return offset
  end
  local pad = align - mod
  return offset + pad, pad
end

function C.ParseObjTypeMethods(t)
  for i, s in ipairs(t) do
    -- parse methods only if they are not already there
    if not s.methods then
      C.ParseObjSubTypeMethods(s)
    end
  end
end

function C.ParseObjSubTypeMethods(t)
  local nproto, pProto = t.nproto, t.pProto
  local methods, vt = {}, {}
  t.methods, t.vt = methods, vt
  if nproto == 0 then return methods end

  local pModuleCtx = t.pModuleCtx
  local ppModuleFunc, ppModuleFuncTypes = readPointer(pModuleCtx + 0x08), readPointer(pModuleCtx + 0x10)
  for i = 1, nproto do
    local pName = readPointer(pProto + 0x00)
    local findex, pindex, hashed_name = readInteger(pProto + 0x08), readInteger(pProto + 0x0C), readInteger(pProto + 0x10)
    
    local vt_offset = nil
    if pindex == 0xFFFFFFFF then
      pindex = nil
    else
      vt_offset = pindex * 0x08 -- offset in vtable (used for virtual calls) (x64)
    end
    
    local ppFunc, ppFuncType = ppModuleFunc + findex * 0x08, ppModuleFuncTypes + findex * 0x08
    local pFunc, pFuncType = readPointer(ppFunc), readPointer(ppFuncType)
    local m = {
      name = readString(pName, 1024, true),
      findex = findex,
      pindex = pindex,
      vt_offset = vt_offset,
      pFunc = pFunc,
      --pFuncType = pFuncType,
      func_type = C.ParseType(pFuncType),
    }
    methods[i] = m
    if pindex then
      vt[pindex] = m
    end
    pProto = pProto + 0x18 -- hl_obj_proto size (0x14) + padding (4)
  end
end

function C.ParseFunType(kind, kind_name, pType)
  local pFuncT = readPointer(pType + 0x08)
  local ppArgsT, pRetT, nargs = readPointer(pFuncT + 0x00), readPointer(pFuncT + 0x08), readInteger(pFuncT + 0x10)
  local pParentT = readPointer(pFuncT + 0x18)

  local arg_types = {}
  local ppArgT = ppArgsT
  for i = 1, nargs do
    local pArgT = readPointer(ppArgT)
    local arg_type = C.ParseShortType(pArgT)
    arg_types[i] = arg_type
    ppArgT = ppArgT + 0x08 -- (x64)
  end
  t = {
    kind = kind,
    kind_name = kind_name,
    nargs = nargs,
    arg_types = arg_types,
    ret_type = C.ParseShortType(pRetT),
    parent_type = (pParentT > 0) and C.ParseShortType(pParentT) or nil,
    pType = pType,
  }
  return t
end
  
function C.ParseVirtualType(kind, kind_name, pType)
  local tvirt = readPointer(pType + 0x08)
  local pFields, nfields = readPointer(tvirt + 0x00), readInteger(tvirt + 0x08)
  local offset = 8

  local fields = {
    begin_offset = offset,
  }
  local res = {
    kind = kind,
    kind_name = kind_name,
    pType = pType,
    nfields = nfields,
    pFields = pFields,
    fields = fields,
    data_size = readInteger(tvirt + 0x0C),
    pIndexes = readPointer(tvirt + 0x10),
    pFieldLookup = readPointer(tvirt + 0x18),
    --nproto = nproto,
    --nbindings = nbindings,
    --name = name,
    --super = super,
    --pProto = pProto,
    --pBindings = pBindings,
    --ppGlobalValue = ppGlobalValue,
    --pModuleCtx = pModuleCtx,
    --pRuntimeObj = pRuntimeObj,
  }

  for i = 1, nfields do
    local pField = pFields + (i - 1) * 0x18 -- sizeof(hl_obj_field) == 0x14 + 4 bytes padding = 0x18
    local f = C.ParseObjTypeField(res, i - 1, offset, pField)
    offset = f.offset + f.size
    fields[i] = f;
  end
  fields.total_size = offset

  return res
end




return C
