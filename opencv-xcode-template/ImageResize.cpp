#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables
cv::Mat src, dst;
char* window_name = "Image Resize Demo";

//////////////////////////////////////////////////////////////////
// function : main
int main( int argc, char** argv )
{
	/// Test image - Make sure it s divisible by 2^{n}
	src = imread( "../res/Lenna.png" );

	if( !src.data ) {
		printf(" No data! -- Exiting the program \n");
		return -1;
	}

	/// Resize image
	cv::resize( src, dst, cv::Size( src.cols*2, src.rows*2 ), 0, 0, CV_INTER_NN );

	/// Create window
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	imshow( window_name, dst );

	cv::waitKey( 5000 );

	return 0;
}