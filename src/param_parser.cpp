//
// Created by isaac on 4/9/18.
//

#include "param_parser.hpp"


namespace po = boost::program_options;

void param_parser(int argc, char** argv){

  po::options_description desc ("Allowed options");
  desc.add_options()
    ("help,h","Help")
    ("kernel-i,i",po::value<int>()->default_value(3),"Kernel row size")
    ("kernel-j,j",po::value<int>()->default_value(3),"Kernel column size")
    ("plot,p",po::value<std::string>()->default_value("convolution_test_image.png"),"Plot")
    ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc,argv,desc),vm);
  po::notify(vm);

  if(vm.count("kernel-i") & vm.count("kernel-j") & !vm.count("plot")){
    //do spatial and frequency convolution
  }else if (vm.count("plot")){
    std::string file_name = vm["plot"].as<std::string>();
    plotConv(file_name);
  }else{
    std::cout<<desc<<std::endl;
    exit(EXIT_SUCCESS);
  }
}
