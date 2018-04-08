#include "runs_per_case.hpp"

int
estimate_runs (int img_size_h, int img_size_v, int kern_size) {
  float estimation;
  int max_img_size_h = 1920;
  int max_img_size_v = 1080;
  int max_kern_size = 1023;
  int max_runs = 20; // subject to change
  int min_runs = 1; // subject to change

  // this formula could be changed
  // maybe the min_runs should be higher
  // maybe the max_runs should be higher, or lower
  // maybe it could be changed to be exponential or quadratic
  // TODO: remove this comment once that is determined
  float numerator = (img_size_v*img_size_h + kern_size*kern_size);
  float denominator = max_img_size_h*max_img_size_v + max_kern_size*max_kern_size;

  // only runs min_runs times when img_size_h and img_size_v are the same as
  // max_img_size_h and max_img_size_v respecitively
  // and
  // kern_size is the same as max_kern_size all at the same time

  estimation = (max_runs - 1)*(1 - (numerator/denominator)) + min_runs;

  return (int)floor (estimation);
}
