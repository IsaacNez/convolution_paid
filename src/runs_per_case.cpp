/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The function defined here returns the number of times to run
 * a filter as a function of the size of the image, and the filter's kernel.
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

#include "runs_per_case.hpp"

int
estimate_runs (int img_size_h, int img_size_v, int kern_size)
{
  float estimation;
  int max_img_size_h = 1920;
  int max_img_size_v = 1080;
  int max_kern_size = 1023;
  int max_runs = 20;
  int min_runs = 3;

  float numerator = (img_size_v*img_size_h + kern_size*kern_size);
  float denominator = max_img_size_h*max_img_size_v + max_kern_size*max_kern_size;

  // only runs min_runs times when img_size_h and img_size_v are the same as
  // max_img_size_h and max_img_size_v respecitively
  // and
  // kern_size is the same as max_kern_size all at the same time

  estimation = (max_runs - 1)*(1 - (numerator/denominator)) + min_runs;

  return (int)floor (estimation);
}
