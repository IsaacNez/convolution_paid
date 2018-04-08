#include "space_convolution.hpp"
#include "constants.hpp"
#include "runs_per_case.hpp"

void
separable (const char* img_filename)
{
  cv::Mat orig = cv::imread (img_file_name, CV_LOAD_IMAGE_GRAYSCALE);
  if (orig.empty ())
  {
    exit (EXIT_FAILURE);
  }
  cv::Mat dst = cv::Mat::zeros (orig.rows, orig.cols, orig.type());
  dst.create (orig.size (), orig.type ());
  int k_sizes = 10;
  int img_sizes = 10;

  int run_times[10][10] = { 0 };

  for (int i = 0; i < k_sizes; i++)
  {
    int current_k_size = kernel_sizes[i];
    int current_img_h_size = image_horizontal_sizes[i];
    int current_img_v_size = image_vertical_sizes[i];

    for (int j = 0; j < img_sizes; j++)
    {
      std::chrono::high_resolution_clock::time_point start = current_time();
      cv::Ptr<cv::FilterEngine> gaussianFilter = cv::createGaussianFilter ( orig.type (), cv::Size(KERNEL_SIZE, KERNEL_SIZE), SIGMA);
      gaussianFilter->apply (orig, dst);
      std::chrono::high_resolution_clock::time_point end = current_time();
      run_times[i][j] = measured_duration (start, end);
    }
  }
}

void
space_convolution (const char* img_filename)
{
  separable (img_filename);
}
