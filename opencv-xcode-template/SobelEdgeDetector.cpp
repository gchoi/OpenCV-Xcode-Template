//
//  SobelEdgeDetector.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/19/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include "SobelEdgeDetector.h"

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#define M_ROWS 3
#define M_COLS 3

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/frozen.jpg");
    
    int nRows = image.rows;
    int nCols = image.cols;
    
    // Convert to gray
    float chRed, chGreen, chBlue;
    float fGray;
    
    for( int j = 0 ; j < nRows - 2 ; j++ ) {
        
        for( int i = 0 ; i < nCols - 2 ; i++ ) {
            
            chBlue  = (float)( image.at<cv::Vec3b>(j,i)[0] );
            chGreen = (float)( image.at<cv::Vec3b>(j,i)[1] );
            chRed   = (float)( image.at<cv::Vec3b>(j,i)[2] );
            
            fGray = 0.21 * chRed + 0.72 * chGreen + 0.07 * chBlue;
            
            
            
            
            
        }
        
    }
    
    
    
    
    
    cv::Mat image_copy;
    cv::Mat image_tmp;
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}