#include <chrono>
#include "timer.hpp"


std::chrono::duration<long, std::micro> Timer::timeDiff() { // Updates m_t and returns the time difference in μs
    std::chrono::duration<long, std::micro> diff =
    std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - m_time);
    m_time = std::chrono::steady_clock::now();
    return diff;
}
