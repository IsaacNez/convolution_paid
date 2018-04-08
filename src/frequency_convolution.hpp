#ifndef FREQUENCY_CONVOLUTION_HPP
#define FREQUENCY_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

void
separable_freq (const char* img_filename);

void
frequency_convolution (const char* img_filename);

#endif // FREQUENCY_CONVOLUTION_HPP
