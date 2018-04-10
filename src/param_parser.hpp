//
// Created by isaac on 4/9/18.
//

#ifndef PROJECT_PARAM_PARSER_HPP
#define PROJECT_PARAM_PARSER_HPP

#include "plot.cpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include "boost/program_options.hpp"

/**
 * Parses the input using boost::program_options
 * @param argc input from the command line: amount of inputs
 * @param argv input from the command line: inputs
 */
void param_parser(int argc, char** argv);

#endif //PROJECT_PARAM_PARSER_HPP
