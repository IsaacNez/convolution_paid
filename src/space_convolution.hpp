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
                                        const cv::Mat& orig);


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
