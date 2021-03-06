//
//  SobelEdgeDetector.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/19/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    cv::Mat src, src_gray;
    cv::Mat grad;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    
    /// Load an image
    src = cv::imread( "../../../../../res/steam_engine.png", 1 );
    
    if( !src.data ) { return -1; }
    
    cv::GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    
    /// Convert it to gray
    cv::cvtColor( src, src_gray, CV_RGB2GRAY );
    
    /// Create window
    cv::namedWindow( "", CV_WINDOW_AUTOSIZE );
    
    /// Generate grad_x and grad_y
    cv::Mat grad_x, grad_y;
    cv::Mat abs_grad_x, abs_grad_y;
    
    /// Gradient X
    cv::Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    
    cv::convertScaleAbs( grad_x, abs_grad_x );
    
    /// Gradient Y
    cv::Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    
    cv::convertScaleAbs( grad_y, abs_grad_y );
    
    /// Total Gradient (approximate)
    cv::addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    
    cv::imshow( "Sobel Edge Detector", grad );
    
    cv::waitKey();
    
    
    return 0;
    
}