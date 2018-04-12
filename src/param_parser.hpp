/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The function defined here processes the parameters passed to the program
 * before starting execution
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

#ifndef PROJECT_PARAM_PARSER_HPP
#define PROJECT_PARAM_PARSER_HPP

#include "plot.cpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include "boost/program_options.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




/**
 * Parses the input using boost::program_options
 * @param argc input from the command line: amount of inputs
 * @param argv input from the command line: inputs
 */
void param_parser(int argc, char** argv);

#endif //PROJECT_PARAM_PARSER_HPP
