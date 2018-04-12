/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The function defined here checks for an argument
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
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "space_convolution.hpp"
#include "frequency_convolution.hpp"
#include "constants.hpp"
#include "param_parser.cpp"

int main (int argc, char** argv)
{
  param_parser(argc,argv);

  exit (EXIT_SUCCESS);
}
