/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The functions defined here plot a matrix of numbers
 * and are used to plot the execution time measured of the image filtering
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

/**
 * Creates all the test cases for frequency and spatial filtering using
 * separable and non-separable kernels
 * @param file_name path to the image to be filtered using gaussian filters.
 */
void plotConv(const std::string& file_name);

/**
 * Plots the data into the respective SVGs using a Python interface through Pyhton.h.
 * @param FSSx x-points refering to spatial or frequency filtering with (Non)Separable Kernel
 * @param FSSy y-points refering to spatial or frequency filtering with (Non)Separable Kernel
 * @param FSSz y-points refering to spatial or frequency filtering with (Non)Separable Kernel
 * @param label label that will appear on the figure stating what the points refers to
 * @param file_name name of the resultant file
 */
void plotpython(const std::vector<double>& FSSx,
                const std::vector<double>& FSSy,
                const std::vector<double>& FSSz,
                std::string label,
                std::string file_name);

/**
 * Plots two sets of data in a same figure.
 * @param FNSSx
 * @param FNSSy
 * @param FNSSz
 * @param FNSFx
 * @param FNSFy
 * @param FNSFz
 * @param label
 * @param label2
 */
void plotpython2(const std::vector<double>& FNSSx,
                 const std::vector<double>& FNSSy,
                 const std::vector<double>& FNSSz,
                 const std::vector<double>& FNSFx,
                 const std::vector<double>& FNSFy,
                 const std::vector<double>& FNSFz,
                 std::string label,
                 std::string label2,
                 std::string zlabel = "Time (in microseconds)",
                 std::string file_name = "F&SFNSK.svg");


double frobenius(const cv::Mat& image);
#endif //PROJECT_PLOT_HPP
