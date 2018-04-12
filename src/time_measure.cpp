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
