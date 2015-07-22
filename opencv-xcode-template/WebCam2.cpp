//
//  WebCam2.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 7/23/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

/* @ function main */
int main(int argc, const char * argv[]) {
    
    // open the default camera
    cv::VideoCapture cap( 0 );
    
    // check if we succeeded
    if( !cap.isOpened() )
        return -1;
    
    cv::namedWindow( "WebCam Frame Capture", 1 );
    
    for( ; ; ) {
        cv::Mat frame;
        
        // get a new frame from camera
        cap >> frame;
        
        cv::imshow( "WebCam Frame Capture", frame );
        
        if( waitKey( 10 ) >= 0) break;
    }
    
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
    
}
