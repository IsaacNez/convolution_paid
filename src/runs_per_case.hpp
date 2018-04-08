/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The function defined here returns the number of times to run
 * a filter as a function of the size of the image, and the filter's kernel.
 * 
 * Created by: David Cordero Chavarría (dcorderoch@ieee.org)
 * Date: 04/08/2018
 * 
 * Copyright (C) 2018
 * 
 * This file is part of a processing and analysis of digital course images project.
 * For modifications, please contact the authors.
 */

#ifndef RUNS_PER_CASE_HPP
#define RUNS_PER_CASE_HPP

#include <cmath>

/**
 * @brief get the number of runs of a filter as a function of image and kernel size
 * @details take the image's horizontal and vertical sizes, as well as the kernel size
 *          to determine the number of times to measure and average the time of the
 *          run filter
 * @param img_size_h image horizontal size in pixels
 * @param img_size_v image vertical size in pixels
 * @param kern_size kernel size in pixels
 */
int
estimate_runs (int img_size_h, int img_size_v, int kern_size);

#endif // RUNS_PER_CASE_HPP
