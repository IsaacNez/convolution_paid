#include <cstdlib>
#include "space_convolution.hpp"
#include "frequency_convolution.hpp"

int main (int argc, char** argv)
{
  space_convolution (argc, argv);
  frequency_convolution (argc, argv);

  exit (EXIT_SUCCESS);
}
