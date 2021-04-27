#pragma once

#include <faabric/util/clock.h>
#include <string>
#define TRACE_ALL

#ifdef TRACE_ALL
#define PROF_START(name)                                                       \
    const faabric::util::TimePoint name = faabric::util::startTimer();
#define PROF_END(name) faabric::util::logEndTimer(#name, name);
#else
#define PROF_START(name)
#define PROF_END(name)
#endif

namespace faabric::util {
faabric::util::TimePoint startTimer();

long getTimeDiffNanos(const faabric::util::TimePoint& begin);

long getTimeDiffMicros(const faabric::util::TimePoint& begin);

double getTimeDiffMillis(const faabric::util::TimePoint& begin);

void logEndTimer(const std::string& label,
                 const faabric::util::TimePoint& begin);

uint64_t timespecToNanos(struct timespec* nativeTimespec);

void nanosToTimespec(uint64_t nanos, struct timespec* nativeTimespec);
}
