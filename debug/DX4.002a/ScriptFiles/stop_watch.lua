-- stop_watch.lua

local clsName = "stop_watch"

if not log_dbg or not log_verbose or not log_info or not log_warn or not log_err then
  log_dbg = log_dbg or function(fmt, ...) end
  log_verbose = log_verbose or function(fmt, ...) end
  log_info = log_info or function(fmt, ...) end
  log_warn = log_warn or function(fmt, ...) end
  log_err = log_err or function(fmt, ...) end
end

local C = {
  cls_name = clsName,
  --started_at = 0,
};
C.__index = C;

function C:new()
  local o = {};
  setmetatable(o, self or C);
  return o;
end

function C:start()
  if not self then log_err("No self! Call %s:start() using ':'", clsName); end
  self.started_at = os.clock();
  return self;
end

function C:stop()
  if not self then log_err("No self! Call %s:stop() using ':'", clsName); end
  if not self.started_at then log_err("%s not started. Call start() first", clsName); end
  self.delta = (self.delta or 0) + (os.clock() - self.started_at);
	self.started_at = nil
  return self.delta;
end

return C;