/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The function defined here checks for an argument, which is to be an
 * image file name, and if there isn't one, tries to set one to a default
 * name of convolution_test_image.png
 * 
 * Created by: David Cordero Chavarría (dcorderoch@ieee.org)
 *             Isaac Núñez (isaacnez@outlook.com)
 *
 * Date: 04/08/2018
 * 
 * Copyright (C) 2018
 * 
 * This file is part of a processing and analysis of digital course images project.
 * For modifications, please contact the authors.
 */

#include <cstdlib>
#include "space_convolution.hpp"
#include "frequency_convolution.hpp"

int main (int argc, char** argv)
{
  const char* test_image = (argc >= 2) ? argv[1] : "convolution_test_image.png";
  space_convolution (test_image);
  frequency_convolution (argc, argv);

  exit (EXIT_SUCCESS);
}
