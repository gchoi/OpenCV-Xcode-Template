//
//  RGB2Gray2.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/21/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    cv::Mat image, image_gray;
    
    /// Load an image
    image = cv::imread("../../../../../res/frozen.jpg");
    
    if( !image.data ) { return -1; }
    
    /// Convert it to gray
    cv::cvtColor( image, image_gray, CV_RGB2GRAY );
    
    /// Create window
    cv::namedWindow( "Image Original", CV_WINDOW_AUTOSIZE );
    cv::namedWindow( "Image Grayed", CV_WINDOW_AUTOSIZE );
    
    /// Show stuff
    cv::imshow( "Image Original", image );
    cv::imshow( "Image Grayed", image_gray );
    
    /// Wait until user press some key
    cv::waitKey();
    
    return 0;
    
}