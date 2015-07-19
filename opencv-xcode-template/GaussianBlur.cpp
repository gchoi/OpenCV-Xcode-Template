//
//  GaussianBlur.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/19/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include "GaussianBlur.h"

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
    cv::Mat image_copy;
    cv::Mat image_tmp;
    
    int nRows = image.rows;
    int nCols = image.cols;
    
    // mask
    float fArMask[3][3];
    
    fArMask[0][0] = 0.0625;
    fArMask[0][1] = 0.125;
    fArMask[0][2] = 0.0625;
    
    fArMask[1][0] = 0.125;
    fArMask[1][1] = 0.25;
    fArMask[1][2] = 0.125;
    
    fArMask[2][0] = 0.0625;
    fArMask[2][1] = 0.125;
    fArMask[2][2] = 0.0625;
    
    // copy image
    image.copyTo( image_copy );
    image.copyTo( image_tmp );
    
    float chRed, chGreen, chBlue;
    float fValRed, fValGreen, fValBlue;
    
    int nIterations = 3;
    
    // Gaussian blur
    for( int nIter = 0 ; nIter < nIterations ; nIter++ ) {
        
        for( int j = 1 ; j < nRows - 2 ; j++ ) {
            
            for( int i = 1 ; i < nCols - 2 ; i++ ) {
                
                chRed = 0.0;
                chGreen = 0.0;
                chBlue = 0.0;
                
                for( int m = 0 ; m < 3 ; m++ ) {
                    
                    for( int k = 0 ; k < 3 ; k++ ) {
                        
                        fValBlue	= (float)( image_tmp.at<cv::Vec3b>( j+(m-1), i+(k-1) )[0] );
                        fValGreen	= (float)( image_tmp.at<cv::Vec3b>( j+(m-1), i+(k-1) )[1] );
                        fValRed		= (float)( image_tmp.at<cv::Vec3b>( j+(m-1), i+(k-1) )[2] );
                        
                        chBlue	+= fArMask[m][k] * fValBlue;
                        chGreen	+= fArMask[m][k] * fValGreen;
                        chRed	+= fArMask[m][k] * fValRed;
                        
                    }
                    
                }
                
                // new image
                image_copy.at<cv::Vec3b>(j,i)[0] = (int)chBlue;
                image_copy.at<cv::Vec3b>(j,i)[1] = (int)chGreen;
                image_copy.at<cv::Vec3b>(j,i)[2] = (int)chRed;
                
                // replace calculated image
                image_copy.copyTo( image_tmp );
                
            }
            
        }
        
    }
    
    // creates window
    cv::namedWindow( "Image Original", 1 );
    cv::namedWindow( "Image Blurred", 1 );
    
    // show stuff
    cv::imshow( "Image Original", image );
    cv::imshow( "Image Blurred", image_copy );
    
    // Wait until user press some key
    cv::waitKey();
    
    return 0;
}