
-- simple_logger.lua--
local simple_logger = {}

-- Define logging levels
simple_logger.levels = {
    ALL = 0,
    DEBUG = 1,
    VERBOSE = 2,
    INFO = 3,
    INFORMATION = 3,
    WARN = 4,
    WARNING = 4,
    ERROR = 5,
    NONE = 6
}

-- Set default logging level to ERROR
simple_logger.current_level = simple_logger.levels.ALL

-- Set logging level
function simple_logger.setLevel(level)
    simple_logger.current_level = level
end

-- Log function
local function log(level_name, level, fmt, ...)
    if level >= simple_logger.current_level then
        local message
        if select("#", ...) > 0 then
            message = string.format(fmt, ...)
        else
            message = fmt
        end
        print(string.format("[%s] %s", level_name, message))
    end
end

-- Define logging functions for each level
function simple_logger.debug(fmt, ...)
    log("DEBUG", simple_logger.levels.DEBUG, fmt, ...)
end

function simple_logger.verbose(fmt, ...)
    log("VERBOSE", simple_logger.levels.VERBOSE, fmt, ...)
end

function simple_logger.info(fmt, ...)
    log("INFO", simple_logger.levels.INFO, fmt, ...)
end

function simple_logger.warn(fmt, ...)
    log("WARN", simple_logger.levels.WARN, fmt, ...)
end

function simple_logger.error(fmt, ...)
    log("ERROR", simple_logger.levels.ERROR, fmt, ...)
end

return simple_logger