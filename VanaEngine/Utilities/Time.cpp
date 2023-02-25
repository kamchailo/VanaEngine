#include "pch.h"
#include "Time.h"
#include <chrono>

uint64_t Time::GetTimeMs()
{
	uint64_t timeSinceEpochMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		).count();
	return timeSinceEpochMilliseconds;
}
