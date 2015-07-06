//
//  fillColor.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 06/07/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include "fillColor.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/gchoi.jpg");
    
    int nRow = image.rows;
    int nCol = image.cols;
    
    if( nRow == 0 && nCol == 0 )
        return 0;
    
    // change colors
    for( int i = 0 ; i < nRow ; i++ ) {
        
        int gray = (int)( 255/(150 - 1) * i );
        
        for( int j = 50 ; j < 250 ; j++ ) {
            image.at<cv::Vec3b>(i,j)[0]= gray;
            image.at<cv::Vec3b>(i,j)[1]= gray;
            image.at<cv::Vec3b>(i,j)[2]= gray;
        }
    }
    
    // display image
    cv::namedWindow( "Image" );
    cv::imshow( "Image", image );
    
    cv::waitKey( 10000 );
    
    return 0;
}