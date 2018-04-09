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
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "space_convolution.hpp"
#include "frequency_convolution.hpp"
#include "constants.hpp"

int main (int argc, char** argv)
{
  int kernel_size = kernel_sizes[3];
  double sigma = ((kernel_size+2)/6);
  cv::Mat gaussian_filter = cv::getGaussianKernel(kernel_size,sigma,CV_32F);
  cv::Mat orig = cv::imread("Lenna.png",CV_LOAD_IMAGE_GRAYSCALE);
  spatial_non_separable_convolution(gaussian_filter,orig);
  frecuency_nonseparable_convolution(gaussian_filter,orig);
  /**const char* test_image = (argc >= 2) ? argv[1] : "convolution_test_image.png";
  space_convolution (test_image);*/
  exit (EXIT_SUCCESS);
}
