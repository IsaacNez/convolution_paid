#include <iostream>
#include "frequency_convolution.hpp"
#include "space_convolution.hpp"

void frequency_nonseparable_convolution(const cv::Mat &gkernel, cv::Mat &image) {


  cv::Mat kernel = cv::Mat::zeros(gkernel.rows,gkernel.rows,gkernel.type());
  generate_gaussian_kernel(gkernel,kernel);

  cv::Mat ipadded;
  cv::Mat kpadded;
  image.convertTo(image,CV_32F);
  int icols = image.cols;
  int irows = image.rows;

  int kcols = kernel.cols;
  int krows = kernel.rows;

  int trows = (krows-1)/2;
  int tcols = (kcols-1)/2;

  int x = icols - kcols;
  int y = irows - krows;

  cv::copyMakeBorder(image,ipadded,0,(kcols-1),0,(kcols-1),cv::BORDER_CONSTANT,cv::Scalar::all (0));
  cv::copyMakeBorder(kernel,kpadded,y/2+trows,y/2+trows+1,x/2+trows,x/2+trows+1,cv::BORDER_CONSTANT,cv::Scalar::all (0));

  cv::Mat result;
  discrete_transform(ipadded,kpadded,trows,tcols,result);
}

void discrete_transform(cv::Mat &ipadded,
                        cv::Mat &kpadded,
                        const int& trows,
                        const int& tcols,
                        cv::Mat &result) {
  cv::Mat grid = cv::Mat::zeros(kpadded.size(),CV_32FC1);
  int a = 1;
  for (int i = 0; i < grid.rows; ++i) {
    for (int j = 0; j < grid.cols; ++j) {
      grid.at<float>(i,j) = a;
      a *= -1;
    }
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
  cv::mulSpectrums(icomplex,kcomplex, icomplex, 0);

  cv::dft(icomplex, ipadded, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);

  int ccx = ipadded.cols/2;
  int ccy = ipadded.rows/2;

  cv::Mat qq0(ipadded, cv::Rect(0, 0, ccx, ccy));   // Top-Left - Create a ROI per quadrant
  cv::Mat qq1(ipadded, cv::Rect(ccx, 0, ccx, ccy));  // Top-Right
  cv::Mat qq2(ipadded, cv::Rect(0, ccy, ccx, ccy));  // Bottom-Left
  cv::Mat qq3(ipadded, cv::Rect(ccx, ccy, ccx, ccy)); // Bottom-Right

  cv::Mat ttmp;                           // swap quadrants (Top-Left with Bottom-Right)
  qq0.copyTo(ttmp);
  qq2.copyTo(qq0);
  ttmp.copyTo(qq2);

  qq1.copyTo(ttmp);                    // swap quadrant (Top-Right with Bottom-Left)
  qq3.copyTo(qq1);
  ttmp.copyTo(qq3);

  cv::normalize(ipadded, ipadded, 0, 1, CV_MINMAX);
  ipadded(cv::Rect(0, 0,ipadded.cols - 2*tcols,ipadded.rows - 2*trows)).copyTo(result);
}