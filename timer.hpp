#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
private:
    std::chrono::steady_clock::time_point m_time;
public:
    Timer() {
        m_time = std::chrono::steady_clock::now();
    }

    std::chrono::duration<long, std::micro> timeDiff();  // Updates m_time and returns the time difference in μs
};

#endif // TIMER_H