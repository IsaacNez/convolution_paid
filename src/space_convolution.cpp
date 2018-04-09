#include "space_convolution.hpp"
#include "constants.hpp"
#include "runs_per_case.hpp"

void spatial_non_separable_convolution(const cv::Mat &gaussian_kernel,
                                        const cv::Mat &orig) {

  cv::Mat dst  = cv::Mat::zeros(orig.rows, orig.cols, orig.type());
  dst.create(orig.size(),orig.type());

  cv::Mat kernel = cv::Mat::zeros(gaussian_kernel.cols,gaussian_kernel.cols,gaussian_kernel.type());
  generate_gaussian_kernel(gaussian_kernel,kernel);

  cv::Point anchor = cv::Point(-1,-1);
  cv::filter2D(orig,dst,-1,kernel,anchor,0,cv::BORDER_DEFAULT);

  /**cv::imshow("CV_Orig",orig);
  cv::imshow("CV_Gaussian_Filter_Space_Non_Separable",dst);
  cv::waitKey();*/
}

void generate_gaussian_kernel(const cv::Mat &gaussian_kernel, cv::Mat &spatial_kernel) {
  cv::Mat transpose = cv::Mat::zeros(gaussian_kernel.cols, gaussian_kernel.rows, gaussian_kernel.type());
  cv::transpose(gaussian_kernel, transpose);
  spatial_kernel = gaussian_kernel * transpose;
}

void
separable_space (const char* img_filename)
{
  cv::Mat orig = cv::imread (img_filename, CV_LOAD_IMAGE_GRAYSCALE);
  if (orig.empty ())
  {
    exit (EXIT_FAILURE);
  }
  cv::Mat dst = cv::Mat::zeros (orig.rows, orig.cols, orig.type());
  dst.create (orig.size (), orig.type ());
  int k_sizes = 10;
  int img_sizes = 10;

  uint64_t run_times[10][10];

  for (int i = 0; i < k_sizes; i++)
  {
    int current_k_size = kernel_sizes[i];
    int current_img_h_size = image_horizontal_sizes[i];
    int current_img_v_size = image_vertical_sizes[i];
    double sigma = (current_k_size + 6 / 2);

    for (int j = 0; j < img_sizes; j++)
    {
      cv::Rect roi_rect = cv::Rect(0, 0, current_img_h_size, current_img_v_size);
      cv::Mat roi = orig (roi_rect);
      std::chrono::high_resolution_clock::time_point start = current_time();
      cv::Ptr<cv::FilterEngine> gaussianFilter = cv::createGaussianFilter ( orig.type (), cv::Size(current_k_size, current_k_size), sigma);
      gaussianFilter->apply (roi, dst);
      std::chrono::high_resolution_clock::time_point end = current_time();
      run_times[i][j] = measured_duration (start, end);
    }
  }
  //plot_space_convolution_run_times (run_times);
}




