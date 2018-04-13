/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * The functions defined here run the frequency gaussian filter
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

#include <iostream>
#include "frequency_convolution.hpp"
#include "space_convolution.hpp"

void frequency_nonseparable_convolution(const cv::Mat &gkernel,
                                        cv::Mat& image2,
                                        cv::Mat& final) {


  cv::Mat kernel = cv::Mat::zeros(gkernel.rows,gkernel.rows,gkernel.type());
  generate_gaussian_kernel(gkernel,kernel);

  cv::Mat ipadded;
  cv::Mat kpadded;
  cv::Mat image;
  image2.convertTo(image,CV_32F);
  int icols = image.cols;
  int irows = image.rows;

  int kcols = kernel.cols;
  int krows = kernel.rows;

  int trows = (krows-1)/2;
  int tcols = (kcols-1)/2;

  cv::copyMakeBorder(image,ipadded,0,(kcols-1),0,(kcols-1),cv::BORDER_CONSTANT,cv::Scalar::all (0));
  cv::copyMakeBorder(kernel,kpadded,irows/2,irows/2-1,icols/2,icols/2-1,cv::BORDER_CONSTANT,cv::Scalar::all (0));

  cv::Mat result;
  discrete_transform(ipadded,kpadded,trows,tcols,result);
  final = result;
}

void discrete_transform(cv::Mat &ipadded,
                        cv::Mat &kpadded,
                        const int& trows,
                        const int& tcols,
                        cv::Mat &result) {
  cv::Mat grid = cv::Mat::zeros(kpadded.size(),CV_32FC1);

  int a = 1;
  assert(grid.cols%2==0);
  for (int i = 0; i < grid.rows; ++i) {
    for (int j = 0; j < grid.cols; ++j) {
      grid.at<float>(i,j) = a;
      a *= -1;
    }
    a*=-1;
  }
  cv::Mat icomplex = cv::Mat::zeros(ipadded.size(), CV_32F);
  cv::Mat kcomplex = cv::Mat::zeros(ipadded.size(), CV_32F);
  cv::Mat zcomplex = cv::Mat::zeros(ipadded.size(), CV_32F);
  cv::Mat planes[] = {cv::Mat_<float>(grid),cv::Mat::zeros(kpadded.size(), CV_32F)};
  cv::Mat complex;

  cv::merge(planes, 2, complex);
  cv::dft(ipadded, icomplex,cv::DFT_COMPLEX_OUTPUT);
  cv::dft(kpadded, kcomplex,cv::DFT_COMPLEX_OUTPUT);

  cv::multiply(kcomplex,complex,kcomplex);
  cv::mulSpectrums(icomplex,kcomplex, icomplex,0,true);

  cv::dft(icomplex, ipadded,cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);

  ipadded(cv::Rect(0,0,ipadded.cols-2*tcols,ipadded.rows-2*trows)).copyTo(result);
}
