//
// Created by isaac on 4/9/18.
//

#ifndef PROJECT_PLOT_HPP
#define PROJECT_PLOT_HPP

#include "frequency_convolution.hpp"
#include "runs_per_case.hpp"
#include "space_convolution.hpp"
#include "constants.hpp"
#include "Python.h"
#include <boost/lexical_cast.hpp>

#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <chrono>

void plotConv(const std::string& file_name);

void plotpython(const std::vector<double> FSSx,
                const std::vector<double> FSSy,
                const std::vector<double> FSSz,

                const std::vector<double> FNSSx,
                const std::vector<double> FNSSy,
                const std::vector<double> FNSSz,

                const std::vector<double> FNSFx,
                const std::vector<double> FNSFy,
                const std::vector<double> FNSFz);
#endif //PROJECT_PLOT_HPP
