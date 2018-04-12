/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The functions defined here run the spatial gaussian filter
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

#ifndef SPACE_CONVOLUTION_HPP
#define SPACE_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "time_measure.hpp"

/**
 * Spacial Filtering using non-separable kernel with a size nx1. It also recieves an
 * image in grayscale or color. It uses filter2D to apply the gaussian filter.
 * @param gaussian_kernel gaussian kernel in the form of nx1.
 * @param orig original image to be filtered
 */
void spatial_non_separable_convolution(const cv::Mat& gaussian_kernel,
                                        const cv::Mat& orig,
                                        cv::Mat& final);


/**
 * @brief Spatial filtering using a separable kernel of size NxN
 * @details take the original image, kernel size, and sigma, and apply filter
 * @param orig the original image to be filtered
 * @param current_k_size the size of the kernel
 * @param sigma the variance of the filters, using sigma = (k_size + 2)/6
 */
void separable_space (const cv::Mat& orig,
                      const int& current_k_size,
                      const double& sigma);

/**
 * computes the non-separable kernel coming from a gaussian kernel in the form nx1
 * spatial_kernel = guassian_kernel*guassian_kernel' to form a matrix nxn
 * @param gaussian_kernel kernel input in the form of nx1
 * @param spatial_kernel output kernel in the form nxn
 */
void generate_gaussian_kernel(const cv::Mat& gaussian_kernel,
                              cv::Mat& spatial_kernel);
#endif // SPACE_CONVOLUTION_HPP
