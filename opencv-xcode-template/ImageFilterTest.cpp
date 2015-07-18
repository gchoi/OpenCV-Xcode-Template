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

#define M_ROWS 3
#define M_COLS 3

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/frozen.jpg");
    cv::Mat image_copy;
    
    image.copyTo(image_copy);
    
    int nRow = image.rows;
    int nCol = image.cols;
    
    // mask
    float fMask[M_ROWS][M_COLS];
    
    for( int i = 0 ; i < M_ROWS ; i++ ) {
        for( int j = 0 ; j < M_COLS ; j++) {
            fMask[i][j] = 0.0;
        }
    }
    
    fMask[0][0] = 0.0625;
    fMask[0][1] = 0.125;
    fMask[0][2] = 0.0625;
    
    fMask[1][0] = 0.125;
    fMask[1][1] = 0.25;
    fMask[1][2] = 0.125;
    
    fMask[2][0] = 0.0625;
    fMask[2][1] = 0.125;
    fMask[2][2] = 0.0625;
    
    int ch1, ch2, ch3;
    ch1 = 0 ; ch2 = 0 ; ch3 = 0;
    
    // sub-matrix
    float fSubMat[M_ROWS][M_COLS][3];
    
    for( int i = 0 ; i < M_ROWS ; i++ ) {
        for( int j = 0 ; j < M_COLS ; j++ ) {
            for( int k = 0 ; k < 3 ; k++ ) {
                fSubMat[i][j][k] = 0.0f;
            }
        }
    }
    
    // test
    
    int i = 0, j = 0;
    
    i = 1; j = 1;
    ch1 = 0 ; ch2 = 0 ; ch3 = 0;
    
    for( int m = 0 ; m < 3 ; m++ ) {
        
        for( int k = 0 ; k < 3 ; k++ ) {
            
            // extract sub-matrix
            //fSubMat[m][k][0] = image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[0];
            //fSubMat[m][k][1] = (int)image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[1];
            //fSubMat[m][k][2] = (int)image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[2];
            
        }
        
    }
    
    
    // end of test
    
    // Gaussian blur processing
    /*
    for( int i = 1 ; i < nRow - 2 ; i++ ) {
        
        for( int j = 1 ; j < nCol - 2 ; j++ ) {
        
            ch1 = 0 ; ch2 = 0 ; ch3 = 0;
            
            for( int m = 0 ; m < 3 ; m++ ) {
                
                for( int k = 0 ; k < 3 ; k++ ) {
                    
                    // extract sub-matrix
                    fSubMat[m][k][0] = (int)image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[0];
                    fSubMat[m][k][1] = (int)image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[1];
                    fSubMat[m][k][2] = (int)image.at<cv::Vec3b>(j + (m-1), i + (k-1) )[2];
                    
                }
                
            }
            
            // convulution
            for( int m = 0 ; m < 3 ; m++ ) {
                
                for( int k = 0 ; k < 3 ; k++ ) {
                    
                    ch1 += fSubMat[m][k][0] * fMask[m][k];
                    ch2 += fSubMat[m][k][1] * fMask[m][k];
                    ch3 += fSubMat[m][k][2] * fMask[m][k];
                    
                }
                
            }
            
            // set Gaussian blurred channels
            image_copy.at<cv::Vec3b>(j,i)[0] = ch1;
            image_copy.at<cv::Vec3b>(j,i)[1] = ch2;
            image_copy.at<cv::Vec3b>(j,i)[2] = ch3;
            
        }
        
    }
     */
    
    // creates window
    //cv::namedWindow("Image Filtering", 1);
    
    // show image
    //cv::imshow("Image Filtering", image_copy);

    // Wait until user press some key
    //waitKey();
    
    return 0;
}