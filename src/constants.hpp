/**
 * This file is part of a program to measure time spent by
 * passing images through gaussian filters, using separable
 * and non-separable filter kernels, in both space, and frequency.
 *
 * This file defines the image and kernel horizontal and vertical dimentions
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

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const int kernel_sizes[] = {3, 131, 259, 387, 515, 643, 771, 899, 1023};
const int image_vertical_sizes[] = {48, 176, 306, 434, 564, 692, 822, 950, 1080};
const int image_horizontal_sizes[] = {64, 296, 528, 760, 992, 1224, 1456, 1688, 1920};

#endif // CONSTANTS_HPP
