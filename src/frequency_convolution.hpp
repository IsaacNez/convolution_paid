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

#ifndef FREQUENCY_CONVOLUTION_HPP
#define FREQUENCY_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/**
 * Computes the frequency convolution using a non-separable kernel.
 * it computes the nxn kernel using the nx1 kernel.
 * @param kernel kernel in the form nx1
 * @param image original image to be filtered
 */
void frequency_nonseparable_convolution(const cv::Mat& kernel,
                                        cv::Mat& image,
                                        cv::Mat& final);

/**
 * Computes the iDFT using the result from the multiplication of spectrums.
 * It also crops the black borders created in the padding and restore the image
 * to its original size.
 * @param image_padded original image with padding
 * @param kernel_padded kernel with padding
 * @param trows amount of rows to crop
 * @param tcols amount of cols to crop
 * @param result image resultant w/o black borders and filtered in frequency
 */
void discrete_transform(cv::Mat& image_padded,
                        cv::Mat& kernel_padded,
                        const int& trows,
                        const int& tcols,
                        cv::Mat& result);

#endif // FREQUENCY_CONVOLUTION_HPP
