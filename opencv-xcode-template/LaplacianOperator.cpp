//
//  LaplacianOperator.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/25/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

/* @ function main */
int main( int argc, char** argv )
{
    
    cv::Mat src, src_gray, dst;
    
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    
    /// Load an image
    src = cv::imread( "../../../../../res/up.jpg", 1 );
    
    if( !src.data ) { return -1; }
    
    /// Remove noise by blurring with a Gaussian filter
    cv::GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    
    /// Convert the image to grayscale
    cv::cvtColor( src, src_gray, COLOR_RGB2GRAY );
    
    /// Apply Laplace function
    cv::Mat abs_dst;
    
    cv::Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
    cv::convertScaleAbs( dst, abs_dst );
    
    /// Create window
    cv::namedWindow( "Origianl Image", WINDOW_AUTOSIZE );
    cv::namedWindow( "Laplacian Image", WINDOW_AUTOSIZE );
    
    /// Show what you got
    cv::imshow( "Origianl Image", src );
    cv::imshow( "Laplacian Image", abs_dst );
    
    cv::waitKey(0);
    
    return 0;
    
}
