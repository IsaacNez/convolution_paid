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


#include "param_parser.hpp"

#include <cassert>

namespace po = boost::program_options;

void param_parser(int argc, char** argv){

  po::options_description desc ("Allowed options");
  desc.add_options()
    ("help,h","Help")
    ("kernel-i,i",po::value<int>()->default_value(3),"Kernel row size")
    ("kernel-j,j",po::value<int>()->default_value(3),"Kernel column size")
    ("plot,p",po::value<std::string>(),"Plot")
    ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc,argv,desc),vm);
  po::notify(vm);

  if(vm.count("kernel-i") & vm.count("kernel-j") & !vm.count("plot")){
    int ki = vm["kernel-i"].as<int>();
    int kj = vm["kernel-i"].as<int>();
    cv::Mat original = cv::imread("convolution_test_image.png",CV_LOAD_IMAGE_GRAYSCALE);
    assert(ki==kj);
    double sigma = ((ki + 2) / 6);
    cv::Mat test;
    cv::Mat gaussian_filter = cv::getGaussianKernel(ki, sigma, CV_32FC1);  //creates the gaussian filter based on the size of the kernel
    spatial_non_separable_convolution(gaussian_filter, original,test);
    frequency_nonseparable_convolution(gaussian_filter, original,test);
  }else if (vm.count("plot")){
    std::string file_name = vm["plot"].as<std::string>();
    plotConv(file_name);
  }else{
    std::cout<<desc<<std::endl;
    exit(EXIT_SUCCESS);
  }
}
