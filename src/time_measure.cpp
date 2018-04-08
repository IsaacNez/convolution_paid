#include "time_measure.hpp"

std::chrono::high_resolution_clock::time_point
current_time ()
{
  return std::chrono::high_resolution_clock::now ();
}

uint64_t
measured_duration (std::chrono::high_resolution_clock::time_point before,
                   std::chrono::high_resolution_clock::time_point after)
{
  return std::chrono::duration<double>(after - before).count();
}
