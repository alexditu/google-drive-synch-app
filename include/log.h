#ifndef __LOG_H_INCLUDED__
#define __LOG_H_INCLUDED__

#include <spdlog/spdlog.h>

inline void configureDefaultLogger() {
	spdlog::set_level(spdlog::level::trace);
}

#endif // __LOG_H_INCLUDED__