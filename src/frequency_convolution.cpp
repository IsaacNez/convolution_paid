#include "frequency_convolution.hpp"

void
separable_freq (const char* img_filename)
{
  cv::Mat orig = cv::imread (img_filename, CV_LOAD_IMAGE_GRAYSCALE);
  if (orig.empty ())
  {
    exit (EXIT_FAILURE);
  }
  // expand input image to optimal size
  cv::Mat padded;
  int m = cv::getOptimalDFTSize ( orig.rows );
  // on the border add zero values
  int n = cv::getOptimalDFTSize ( orig.cols );
  cv::copyMakeBorder (orig, padded, 0, m - orig.rows, 0, n - orig.cols, cv::BORDER_CONSTANT, cv::Scalar::all (0));

  cv::Mat planes[] = {cv::Mat_<float> (padded), cv::Mat::zeros (padded.size (), CV_32F)};
  cv::Mat complexI;
  // Add to the expanded another plane with zeros
  cv::merge (planes, 2, complexI);

  // this way the result may fit in the source cv::Matrix
  cv::dft (complexI, complexI);

  // compute the magnitude and switch to logarithmic scale
  // => log (1 + sqrt (Re (DFT (orig))^2 + Im (DFT (orig))^2))
  // planes[0] = Re (DFT (orig), planes[1] = Im (DFT (orig))
  cv::split (complexI, planes);
  // planes[0] = magnitude
  cv::magnitude (planes[0], planes[1], planes[0]);
  cv::Mat magI = planes[0];

  // switch to logarithmic scale
  magI += cv::Scalar::all (1);
  cv::log (magI, magI);

  // crop the spectrum, if it has an odd number of rows or columns
  magI = magI (cv::Rect (0, 0, magI.cols & -2, magI.rows & -2));

  // rearrange the quadrants of Fourier image  so that the origin is at the image center
  int cx = magI.cols/2;
  int cy = magI.rows/2;

  // Top-Left - Create a ROI per quadrant
  cv::Mat q0 (magI, cv::Rect (0, 0, cx, cy));
  // Top-Right
  cv::Mat q1 (magI, cv::Rect (cx, 0, cx, cy));
  // Bottom-Left
  cv::Mat q2 (magI, cv::Rect (0, cy, cx, cy));
  // Bottom-Right
  cv::Mat q3 (magI, cv::Rect (cx, cy, cx, cy));

  // swap quadrants (Top-Left with Bottom-Right)
  cv::Mat tmp;
  q0.copyTo (tmp);
  q3.copyTo (q0);
  tmp.copyTo (q3);

  // swap quadrant (Top-Right with Bottom-Left)
  q1.copyTo (tmp);
  q2.copyTo (q1);
  tmp.copyTo (q2);

  // Transform the cv::Matrix with float values into a
  // viewable image form (float between values 0 and 1).
  cv::normalize (magI, magI, 0, 1, CV_MINMAX);
}

void frequency_convolution (const char* img_filename)
{
}
