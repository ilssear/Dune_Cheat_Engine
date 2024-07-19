-- err.lua --

-- comment the following line to disable global debug logging
-- local dbg = printf
if not dbg then dbg = function(fmt, ...) end end

_G.dbg = dbg

function string:LF2CRLF()
  return self:gsub("\r\n", "\n"):gsub("\n", "\r\n")
end

function xerr(msg)
  msg = ("%s\n%s\n"):format(msg or "", debug.traceback())
  return msg
end

function xerrp(msg)
  msg = ("\n%s\n%s\n"):format(msg or "", debug.traceback())
  printf("ERROR: %s", msg)
  return msg
end

function format(fmt, ...)
  local ok, msg = xpcall(string.format, xerr, fmt, ...)
  --msg = msg:LF2CRLF()
  if not ok then error(msg .. "\n" .. debug.traceback(), 2) end
  return msg
end

org_printf = org_printf or rawget(_G, "printf")

local function printf(fmt, ...)
  local ok, msg = xpcall(string.format, xerr, fmt, ...)
  msg = msg:LF2CRLF()
  if not ok then error(msg, 2) end
  print(msg)
end

rawset(_G, "printf", printf)

function wrn(fmt, ...)
  local ok, msg = xpcall(string.format, xerr, fmt, ...)
  --msg = msg:LF2CRLF()
  msg = msg .. "\n" .. debug.traceback()
  if not ok then error(msg, 2) end
  print("WRN: " .. msg)
end

function errn(level, fmt, ...)
  local msg = fmt:format(...)
  printf("ERROR: %s\n%s", msg, debug.traceback())
  error(msg, level+1)
end

function err(fmt, ...)
  errn(2, fmt, ...)
end
package.loaded .err = true
	
