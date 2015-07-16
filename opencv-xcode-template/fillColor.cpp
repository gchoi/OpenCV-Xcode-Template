//
//  fillColor.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 06/07/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include "fillColor.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/gchoi.jpg");
    int nRow = image.rows;
    int nCol = image.cols;
    
    // change colors
    cv::string tmp1, tmp2, filename;
    tmp1 = "../../../../../img/";
    tmp2 = ".jpg";
    
    int step = 0;
    int cnt = 0;
    
    while( step < nCol - 20 ) {
        image = cv::imread("../../../../../res/gchoi.jpg");
        
        for( int i = 0 ; i < nRow ; i++ ) {
            
            int gray = (int)( 255/(150 - 1) * i );
            
            for( int j = step ; j < step + 20 ; j++ ) {
                image.at<cv::Vec3b>(i,j)[0]= gray;
                image.at<cv::Vec3b>(i,j)[1]= gray;
                image.at<cv::Vec3b>(i,j)[2]= gray;
            }
        }
        
        filename = tmp1 + std::to_string(cnt) + tmp2;
        
        cv::imwrite(filename, image);
        
        step += 20;
        cnt++;
    }
        
    return 0;
}