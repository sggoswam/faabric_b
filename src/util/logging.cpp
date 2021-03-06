#include <faabric/util/config.h>
#include <faabric/util/logging.h>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace faabric::util {
static std::shared_ptr<spdlog::logger> logger;
static bool isInitialised = false;

void initLogging()
{
    if (isInitialised) {
        return;
    }

    // Initialise the logger
    logger = spdlog::stderr_color_mt("console");

    // Work out log level from environment
    SystemConfig& conf = faabric::util::getSystemConfig();
    if (conf.logLevel == "debug") {
        spdlog::set_level(spdlog::level::debug);
    } else if (conf.logLevel == "trace") {
        spdlog::set_level(spdlog::level::trace);
    } else if (conf.logLevel == "off") {
        spdlog::set_level(spdlog::level::off);
    } else {
        spdlog::set_level(spdlog::level::info);
    }

    isInitialised = true;
}

std::shared_ptr<spdlog::logger> getLogger()
{
    if (!isInitialised) {
        initLogging();
    }

    return logger;
}
}
