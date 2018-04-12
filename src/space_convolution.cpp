#include "space_convolution.hpp"
#include "constants.hpp"
#include "runs_per_case.hpp"

void spatial_non_separable_convolution(const cv::Mat &gaussian_kernel,
                                        const cv::Mat &orig,
                                        cv::Mat& final) {

  cv::Mat dst  = cv::Mat::zeros(orig.rows, orig.cols, orig.type());
  dst.create(orig.size(),orig.type());

  cv::Mat kernel = cv::Mat::zeros(gaussian_kernel.cols,gaussian_kernel.cols,gaussian_kernel.type());
  generate_gaussian_kernel(gaussian_kernel,kernel);

  cv::Point anchor = cv::Point(-1,-1);
  cv::filter2D(orig,dst,-1,kernel,anchor,0,cv::BORDER_DEFAULT);

  final = dst;
  //std::cout << dst.depth()<<std::endl;
  //cv::imwrite("result.png",dst);
}

void generate_gaussian_kernel(const cv::Mat &gaussian_kernel, cv::Mat &spatial_kernel) {
  cv::Mat transpose = cv::Mat::zeros(gaussian_kernel.cols, gaussian_kernel.rows, gaussian_kernel.type());
  cv::transpose(gaussian_kernel, transpose);
  spatial_kernel = gaussian_kernel * transpose;
}

void
separable_space (const cv::Mat& orig,
                 const int& current_k_size,
                 const double& sigma)
{
  if (orig.empty ())
  {
    exit (EXIT_FAILURE);
  }
  cv::Mat dst = cv::Mat::zeros (orig.rows, orig.cols, orig.type());
  dst.create (orig.size (), orig.type ());
  cv::Ptr<cv::FilterEngine> gaussianFilter = cv::createGaussianFilter ( orig.type (), cv::Size(current_k_size, current_k_size), sigma);
  gaussianFilter->apply (orig, dst);
}




