//
//  RGB2Gray.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/21/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#define M_ROWS 3
#define M_COLS 3

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    /// Load an image
    cv::Mat image = cv::imread("../../../../../res/frozen.jpg");
    cv::Mat image_gray;
    
    /// Copy image
    image.copyTo( image_gray );
    
    int nRows = image.rows;
    int nCols = image.cols;
    
    /// Convert to gray
    float fGray = 0.0f;
    float chBlue, chGreen, chRed;
    
    for( int j = 0 ; j < nRows ; j++ ) {
        
        for( int i = 0 ; i < nCols ; i++ ) {
            
            chBlue	= (float)( image.at<cv::Vec3b>(j,i)[0] );
            chGreen	= (float)( image.at<cv::Vec3b>(j,i)[1] );
            chRed	= (float)( image.at<cv::Vec3b>(j,i)[2] );
            
            fGray = 0.2126f * chRed + 0.7152f * chGreen + 0.0722f * chBlue;
            
            if( fGray < 0.0 ) fGray = 0.0f;
            if( fGray > 255.0 ) fGray = 255.0f;
            
            image_gray.at<cv::Vec3b>(j,i)[0] = (int)fGray;
            image_gray.at<cv::Vec3b>(j,i)[1] = (int)fGray;
            image_gray.at<cv::Vec3b>(j,i)[2] = (int)fGray;
            
        }
        
    }
    
    /// Creates window
    cv::namedWindow( "Image Original", CV_WINDOW_AUTOSIZE );
    cv::namedWindow( "Image Grayed", CV_WINDOW_AUTOSIZE );
    
    /// Show stuff
    cv::imshow( "Image Original", image );
    cv::imshow( "Image Grayed", image_gray );
    
    /// Wait until user press some key
    cv::waitKey();
    
    return 0;
    
}