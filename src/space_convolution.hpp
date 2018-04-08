#ifndef SPACE_CONVOLUTION_HPP
#define SPACE_CONVOLUTION_HPP

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "time_measure.hpp"

void
separable_space (const char* img_filename);

void
space_convolution (const char* img_filename);

#endif // SPACE_CONVOLUTION_HPP
