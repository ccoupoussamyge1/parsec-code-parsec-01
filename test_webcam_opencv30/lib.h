
#ifndef LIB_H 
#define LIB_H
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace cv;
Mat det_contour (Mat frame);
Mat seuillage  (Mat frame);

#endif
