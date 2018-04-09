#ifndef SPACE_CONVOLUTION_HPP
#define SPACE_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "time_measure.hpp"

void spatial_non_separable_convolution(const cv::Mat& gaussian_kernel,
                                        const cv::Mat& orig);


void separable_space (const char* img_filename);

void generate_gaussian_kernel(const cv::Mat& gaussian_kernel,
                              cv::Mat& spatial_kernel);
#endif // SPACE_CONVOLUTION_HPP
