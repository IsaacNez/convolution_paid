//
// Created by isaac on 4/9/18.
//

#include "plot.hpp"
using boost::lexical_cast;
void plotConv(std::string& file_name){
  int k_sizes = 2;//sizeof(kernel_sizes)/ sizeof(*kernel_sizes);

  cv::Mat original = cv::imread(file_name,CV_LOAD_IMAGE_GRAYSCALE);

  std::vector<double> testFSSx(k_sizes); //point3D of plot using FSS
  std::vector<double> testFNSSx(k_sizes); //point3D of plot using FNSS
  std::vector<double> testFNSFx(k_sizes); //point3D of plot using FNSF

  std::vector<double> testFSSy(k_sizes); //point3D of plot using FSS
  std::vector<double> testFNSSy(k_sizes); //point3D of plot using FNSS
  std::vector<double> testFNSFy(k_sizes); //point3D of plot using FNSF

  std::vector<double> testFSSz(k_sizes); //point3D of plot using FSS
  std::vector<double> testFNSSz(k_sizes); //point3D of plot using FNSS
  std::vector<double> testFNSFz(k_sizes); //point3D of plot using FNSF
  for(int i = 0; i < k_sizes; ++i) {


    int kernel_size = kernel_sizes[i];
    double sigma = ((kernel_size + 2) / 6);

    cv::Mat gaussian_filter = cv::getGaussianKernel(kernel_size, sigma, CV_32F);

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
        frecuency_nonseparable_convolution(gaussian_filter, orig);
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

  std::string sFSSx = "x=[";
  std::string sFSSy = "y=[";
  std::string sFSSz = "z=[";
  for (int i = 1; i < size; ++i) {
    std::string numberx = lexical_cast<std::string>(FNSSx.at(i));
    std::string numbery = lexical_cast<std::string>(FNSSy.at(i));
    std::string numberz = lexical_cast<std::string>(FNSSz.at(i));
    sFSSx += (i == size-1)? numberx:(numberx+",");
    sFSSy += (i == size-1)? numbery:(numbery+",");
    sFSSz += (i == size-1)? numberz:(numberz+",");
  }
  sFSSx += "]";
  sFSSy += "]";
  sFSSz += "]";

  Py_Initialize();
  PyRun_SimpleString("import numpy as np");
  PyRun_SimpleString("import matplotlib.pyplot as plt");
  PyRun_SimpleString("from mpl_toolkits.mplot3d import Axes3D");
  PyRun_SimpleString(sFSSx.c_str());
  PyRun_SimpleString(sFSSy.c_str());
  PyRun_SimpleString(sFSSz.c_str());
  PyRun_SimpleString("print x");
  PyRun_SimpleString("print y");
  PyRun_SimpleString("print z");
  PyRun_SimpleString("fig = plt.figure()");
  PyRun_SimpleString("ax = fig.add_subplot(111, projection='3d')");
  PyRun_SimpleString("ax.scatter(x,y,z)");
  PyRun_SimpleString("ax.set_xlabel('Kernel size')");
  PyRun_SimpleString("ax.set_ylabel('Image Size (height)')");
  PyRun_SimpleString("ax.set_zlabel('Time (in microseconds)')");
  PyRun_SimpleString("plt.show()");
  Py_Exit(0);

}
