#ifndef FREQUENCY_CONVOLUTION_HPP
#define FREQUENCY_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void frecuency_nonseparable_convolution(const cv::Mat& kernel,
                                        const cv::Mat& image);
void discrete_transform(cv::Mat& image_padded,
                        const cv::Mat& kernel_padded,
                        const int& trows,
                        const int& tcols,
                        cv::Mat& result);

#endif // FREQUENCY_CONVOLUTION_HPP
