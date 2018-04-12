/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The functions defined here measure time of execution
 * using std::chrono::high_resolution_clock
 * 
 * Created by: David Cordero Chavarría (dcorderoch@ieee.org)
 *             Isaac Núñez Araya (isaacnez@outlook.com)

 * Date: 04/08/2018
 * 
 * Copyright (C) 2018
 * 
 * This file is part of a processing and analysis of digital course images project.
 * For modifications, please contact the authors.
 */

#ifndef TIME_MEASURE_HPP
#define TIME_MEASURE_HPP

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstddef>

/**
 * @brief Get a high resolution time point with std::chrono::high_resolution_clock
 */
std::chrono::high_resolution_clock::time_point
current_time ();

/**
 * @brief Get the time length or duration of an event by passing two time points
 * @param before time_point before starting a computation
 * @param after time_point after ending a computation
 */
uint64_t
measured_duration (std::chrono::high_resolution_clock::time_point before,
                   std::chrono::high_resolution_clock::time_point after);

#endif // TIME_MEASURE_HPP
