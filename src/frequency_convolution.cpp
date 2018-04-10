#include <iostream>
#include "frequency_convolution.hpp"
#include "space_convolution.hpp"

void frecuency_nonseparable_convolution(const cv::Mat &gkernel, const cv::Mat &image) {
  cv::Mat kernel = cv::Mat::zeros(gkernel.rows,gkernel.rows,gkernel.type());

  generate_gaussian_kernel(gkernel,kernel);

  cv::Mat ipadded,kpadded;

  int icols = image.cols;
  int irows = image.rows;

  int kcols = kernel.cols;
  int krows = kernel.rows;

  int trows = (krows-1)/2;
  int tcols = (kcols-1)/2;

  cv::copyMakeBorder(image,ipadded,0,krows-1,0,kcols-1,cv::BORDER_CONSTANT,cv::Scalar::all (0));
  cv::copyMakeBorder(kernel,kpadded,0,irows-1,0,icols-1,cv::BORDER_CONSTANT,cv::Scalar::all (0));

  cv::Mat result = cv::Mat::zeros(irows,icols,ipadded.type());
  discrete_transform(ipadded,kpadded,trows,tcols,result);
}

void discrete_transform(cv::Mat &ipadded,
                        const cv::Mat &kpadded,
                        const int& trows,
                        const int& tcols,
                        cv::Mat &result) {

  cv::Mat iplanes[] = {cv::Mat_<float>(ipadded), cv::Mat::zeros(ipadded.size(), CV_32F)};
  cv::Mat kplanes[] = {cv::Mat_<float>(kpadded), cv::Mat::zeros(kpadded.size(), CV_32F)};

  cv::Mat icomplex, kcomplex;

  cv::merge(iplanes, 2, icomplex);
  cv::merge(kplanes, 2, kcomplex);

  cv::dft(icomplex, icomplex);
  cv::dft(kcomplex, kcomplex);

  cv::mulSpectrums(icomplex, kcomplex, icomplex, 0);

  cv::dft(icomplex, ipadded, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);

  cv::normalize(ipadded, ipadded, 0, 1, CV_MINMAX);
  ipadded(cv::Rect(tcols, trows,ipadded.cols - 2*tcols,ipadded.rows - 2*trows)).copyTo(result);
}