#include "space_convolution.hpp"
#include "constants.hpp"
#include "runs_per_case.hpp"

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

void
space_convolution (const char* img_filename)
{
  separable_space (img_filename);
}
