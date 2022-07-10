#pragma once

#include <chrono>

class Timer {
private:
  std::chrono::steady_clock::time_point time;

public:
  Timer() { time = std::chrono::steady_clock::now(); }

  std::chrono::duration<long, std::micro>
  timeDiff(); // Updates m_time and returns the time difference in μs
};