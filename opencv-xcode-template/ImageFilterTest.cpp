//
//  ImageFilterTest.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 17/07/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include "ImageFilterTest.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/frozen.jpg");
    //int nRow = image.rows;
    //int nCol = image.cols;
    
    
    
    // creates window
    cv::namedWindow("Image Filtering", 1);
    
    // show image
    cv::imshow("Image Filtering", image);

    // Wait until user press some key
    waitKey();
    
    return 0;
}