//
//  WebCam3.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/23/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <stdlib.h>

using namespace std;
using namespace cv;

/* @ function main */
int main(int argc, const char * argv[]) {
    
    // open the default camera
    cv::VideoCapture cap( 0 );
    
    cv::Mat edges;
    
    // check if we succeeded
    if( !cap.isOpened() )
        return -1;
    
    cv::namedWindow( "WebCam Frame Capture", 1 );
    
    for( ; ; ) {
        cv::Mat frame;
        
        // get a new frame from camera
        cap >> frame;
        
        cvtColor( frame, edges, COLOR_BGR2GRAY );
        cv::GaussianBlur( edges, edges, Size (7, 7 ), 1.5, 1.5 );
        cv::Canny( edges, edges, 0, 30, 3 );
        
        cv::imshow( "WebCam Frame Capture", edges );
        
        if( waitKey( 10 ) >= 0) break;
    }
    
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
    
}
