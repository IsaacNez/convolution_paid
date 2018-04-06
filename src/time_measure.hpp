#ifndef TIME_MEASURE_HPP
#define TIME_MEASURE_HPP

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

std::chrono::high_resolution_clock::time_point
current_time ();

std::chrono::duration<double>
measured_duration (std::chrono::high_resolution_clock::time_point before,
                   std::chrono::high_resolution_clock::time_point after);

#endif // TIME_MEASURE_HPP
