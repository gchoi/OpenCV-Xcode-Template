#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h>

using namespace cv;

//////////////////////////////////////////////////////////////////
// function : main
int main( int argc, char** argv )
{
    // frame capture from webcam
    cv::VideoCapture capture(0);
 
	// is camera opened?
    if( !capture.isOpened() ) {
        std::cerr << "Cannot open camera" << std::endl;
        return 0;
    }

	// create a window
    cv::namedWindow( "Webcam", 1 );

	// while loop for image capture from webcam
	while( true ) {
		bool frame_valid = true;
 
        cv::Mat frame;
 
        try {
			// get a new frame from webcam
            capture >> frame;
        }
		catch( cv::Exception& e ) {
            std::cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            frame_valid = false;
        }

		if ( frame_valid ) {
			try {
				// print the output
                cv::imshow( "Webcam", frame );
			}
			catch( cv::Exception& e ) {
                std::cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            }
		}

		if ( cv::waitKey( 30 ) >= 0 ) break;
	}


	return 0;
}