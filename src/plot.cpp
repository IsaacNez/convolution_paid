//
// Created by isaac on 4/9/18.
//

#include "plot.hpp"
using boost::lexical_cast;
void plotConv(std::string& file_name){
  int k_sizes = sizeof(kernel_sizes)/ sizeof(*kernel_sizes);

  cv::Mat original = cv::imread(file_name,CV_LOAD_IMAGE_GRAYSCALE);

  if(original.empty()){
    exit(EXIT_FAILURE);
  }
  if((original.rows < 1080) & (original.cols < 1920)){
    std::cout<< "Image size is not accepted, must be 1920x1080" <<std::endl;
    exit(EXIT_FAILURE);
  }


  std::vector<double> testFSSx(k_sizes);  //x points of 3Dplot with Spatial Filtering and Separable Kernel
  std::vector<double> testFNSSx(k_sizes); //x points of 3Dplot with Spatial Filtering and Non-Separable Kernel
  std::vector<double> testFNSFx(k_sizes); //x points of 3Dplot with Frequency Filtering and Non-Separable Kernel

  std::vector<double> testFSSy(k_sizes);  //y points of 3Dplot with Spatial Filtering and Separable Kernel
  std::vector<double> testFNSSy(k_sizes); //y points of 3Dplot with Spatial Filtering and Non-Separable Kernel
  std::vector<double> testFNSFy(k_sizes); //y points of 3Dplot with Frequency Filtering and Non-Separable Kernel

  std::vector<double> testFSSz(k_sizes);  //z points of 3Dplot with Spatial Filtering and Separable Kernel
  std::vector<double> testFNSSz(k_sizes); //z points of 3Dplot with Spatial Filtering and Non-Separable Kernel
  std::vector<double> testFNSFz(k_sizes); //z points of 3Dplot with Frequency Filtering and Non-Separable Kernel
  for(int i = 0; i < k_sizes; ++i) {


    int kernel_size = kernel_sizes[i];
    double sigma = ((kernel_size + 2) / 6);

    cv::Mat gaussian_filter = cv::getGaussianKernel(kernel_size, sigma, CV_32F);  //creates the gaussian filter based on the size of the kernel

    for (int j = 0; j < k_sizes; ++j) {
      int vertical_size = image_vertical_sizes[j];
      int horizon_size = image_horizontal_sizes[j];

      testFSSx.push_back(kernel_size);
      testFNSSx.push_back(kernel_size);
      testFNSFx.push_back(kernel_size);

      testFSSy.push_back(vertical_size);
      testFNSSy.push_back(vertical_size);
      testFNSFy.push_back(vertical_size);

      cv::Rect roi_rect = cv::Rect(0,0,horizon_size,vertical_size);
      cv::Mat orig = original(roi_rect);

      int runs = estimate_runs(horizon_size, vertical_size, kernel_size);

      double time = 0.0f;
      for (int k = 0; k < runs; ++k) {

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        spatial_non_separable_convolution(gaussian_filter, orig);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        time += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      }
      testFNSSz.push_back(time / runs);
      time = 0.0f;

      for (int k = 0; k < runs; ++k) {

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        frequency_nonseparable_convolution(gaussian_filter, orig);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        time += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      }
      testFNSFz.push_back(time / runs);
      time = 0.0f;

      for (int k = 0; k < runs; ++k) {

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        separable_space(orig, kernel_size, sigma);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        time += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      }
      testFSSz.push_back(time / runs);
    }
  }

  plotpython(testFSSx,
              testFSSy,
              testFSSz,
              testFNSSx,
              testFNSSy,
              testFNSSz,
              testFNSFx,
              testFNSFy,
              testFNSFz);


}

void plotpython(const std::vector<double> FSSx,
                const std::vector<double> FSSy,
                const std::vector<double> FSSz,
                const std::vector<double> FNSSx,
                const std::vector<double> FNSSy,
                const std::vector<double> FNSSz,
                const std::vector<double> FNSFx,
                const std::vector<double> FNSFy,
                const std::vector<double> FNSFz) {

  int size = FNSSx.size();

  std::string sFSSx = "[";
  std::string sFSSy = "[";
  std::string sFSSz = "[";

  std::string sFNSSx = "[";
  std::string sFNSSy = "[";
  std::string sFNSSz = "[";

  std::string sFNSFx = "[";
  std::string sFNSFy = "[";
  std::string sFNSFz = "[";

  for (int i = 1; i < size; ++i) {
    std::string numberx = lexical_cast<std::string>(FSSx.at(i));
    std::string numbery = lexical_cast<std::string>(FSSy.at(i));
    std::string numberz = lexical_cast<std::string>(FSSz.at(i));
    sFSSx += (i == size-1)? numberx:(numberx+",");
    sFSSy += (i == size-1)? numbery:(numbery+",");
    sFSSz += (i == size-1)? numberz:(numberz+",");

    numberx = lexical_cast<std::string>(FNSSx.at(i));
    numbery = lexical_cast<std::string>(FNSSy.at(i));
    numberz = lexical_cast<std::string>(FNSSz.at(i));
    sFNSSx += (i == size-1)? numberx:(numberx+",");
    sFNSSy += (i == size-1)? numbery:(numbery+",");
    sFNSSz += (i == size-1)? numberz:(numberz+",");

    numberx = lexical_cast<std::string>(FNSFx.at(i));
    numbery = lexical_cast<std::string>(FNSFy.at(i));
    numberz = lexical_cast<std::string>(FNSFz.at(i));
    sFNSFx += (i == size-1)? numberx:(numberx+",");
    sFNSFy += (i == size-1)? numbery:(numbery+",");
    sFNSFz += (i == size-1)? numberz:(numberz+",");
  }
  sFSSx += "]";
  sFSSy += "]";
  sFSSz += "]";

  sFNSSx += "]";
  sFNSSy += "]";
  sFNSSz += "]";

  sFNSFx += "]";
  sFNSFy += "]";
  sFNSFz += "]";
  std::string commandSK = "ax.plot("+sFSSx+","+sFSSy+","+sFSSz+",'*',color='red',label='Spatial Filtering using Separable Kernel')";
  std::string commandNSK = "ax.plot("+sFNSSx+","+sFNSSy+","+sFNSSz+",'x',color='green',label='Spatial Filtering using Non-Separable Kernel')";
  std::string commandFNSK = "ax.plot("+sFNSFx+","+sFNSFy+","+sFNSFz+",'+',color='blue',label='Frequency Filtering using Separable Kernel')";
  Py_Initialize();
  PyRun_SimpleString("import numpy as np");
  PyRun_SimpleString("import matplotlib.pyplot as plt");
  PyRun_SimpleString("from mpl_toolkits.mplot3d import Axes3D");
  PyRun_SimpleString("ax = plt.subplot(111, projection='3d')");
  PyRun_SimpleString(commandSK.c_str());
  PyRun_SimpleString("ax.set_xlabel('Kernel size')");
  PyRun_SimpleString("ax.set_ylabel('Image Size (height)')");
  PyRun_SimpleString("ax.set_zlabel('Time (in microseconds)')");
  PyRun_SimpleString("plt.legend(loc='upper left', numpoints=1, ncol=1, fontsize=8, bbox_to_anchor=(0, 0))");
  PyRun_SimpleString("plt.savefig('SFSK.svg')");

  PyRun_SimpleString("ax = plt.subplot(111, projection='3d')");
  PyRun_SimpleString(commandNSK.c_str());
  PyRun_SimpleString("ax.set_xlabel('Kernel size')");
  PyRun_SimpleString("ax.set_ylabel('Image Size (height)')");
  PyRun_SimpleString("ax.set_zlabel('Time (in microseconds)')");
  PyRun_SimpleString("plt.legend(loc='upper left', numpoints=1, ncol=1, fontsize=8, bbox_to_anchor=(0, 0))");
  PyRun_SimpleString("plt.savefig('SFNSK.svg')");

  PyRun_SimpleString("ax = plt.subplot(111, projection='3d')");
  PyRun_SimpleString(commandFNSK.c_str());
  PyRun_SimpleString("ax.set_xlabel('Kernel size')");
  PyRun_SimpleString("ax.set_ylabel('Image Size (height)')");
  PyRun_SimpleString("ax.set_zlabel('Time (in microseconds)')");
  PyRun_SimpleString("plt.legend(loc='upper left', numpoints=1, ncol=1, fontsize=8, bbox_to_anchor=(0, 0))");
  PyRun_SimpleString("plt.savefig('FFNSK.svg')");

  PyRun_SimpleString("ax = plt.subplot(111, projection='3d')");
  PyRun_SimpleString(commandNSK.c_str());
  PyRun_SimpleString(commandFNSK.c_str());
  PyRun_SimpleString("ax.set_xlabel('Kernel size')");
  PyRun_SimpleString("ax.set_ylabel('Image Size (height)')");
  PyRun_SimpleString("ax.set_zlabel('Time (in microseconds)')");
  PyRun_SimpleString("plt.legend(loc='upper left', numpoints=1, ncol=1, fontsize=8, bbox_to_anchor=(0, 0))");
  PyRun_SimpleString("plt.savefig('F&SFNSK.svg')");
  Py_Exit(0);

}
