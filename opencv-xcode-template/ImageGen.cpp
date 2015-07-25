#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

//////////////////////////////////////////////////////////////////
// function : main
int main( int argc, char** argv )
{
	/// Test image
	cv::Mat src(200, 200, CV_8UC3, Scalar(0,0,255));

	if( !src.data ) {
		printf(" No data! -- Exiting the program \n");
		return -1;
	}

	/// Create window
	string window_name = "Image";
	cv::namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	cv::imshow( window_name, src );

	cv::waitKey( 5000 );

	return 0;
}