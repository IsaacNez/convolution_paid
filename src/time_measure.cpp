#include "time_measure.hpp"

std::chrono::high_resolution_clock::time_point
current_time ()
{
  return std::chrono::high_resolution_clock::now ();
}

std::chrono::duration<double>
measured_duration (std::chrono::high_resolution_clock::time_point before,
                   std::chrono::high_resolution_clock::time_point after)
{
  return std::chrono::duration_cast<std::chrono::duration<double> >(after - before);
}
