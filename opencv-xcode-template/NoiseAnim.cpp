#include "stdafx.h"
#include <opencv2/opencv.hpp>

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

// function prototypes
void AddNoise( cv::Mat &image, int nCount );


/* @ function main */
int main( int argc, char** argv )
{
	/// Load an image
	cv::Mat image = cv::imread( "../res/pixar.jpg", 1 );
	
	// display image
	cv::namedWindow( "Noise Animation" );

	//
	for( ; ; ) {
		cv::Mat noise;

		// copy from image to noise
		image.copyTo( noise );

		// call function to add noise
		AddNoise( noise, 3000 );

		// show noise image
		cv::imshow( "Noise Animation", noise );

		// eixt when user presse some key
		if( waitKey( 10 ) >= 0) break;

		// delay a while (in miliseconds)
		Sleep( 50 );
	}
	
    return 0;

}


/* @ function AddNoise */
void AddNoise( cv::Mat &image, int nCount )
{

	for ( int k = 0 ; k < nCount ; k++ ) {
		// rand() is the MFC random number generator
		int i = rand()%image.cols;
		int j = rand()%image.rows;
		
		if ( image.channels() == 1 ) { // gray-level image
			image.at<uchar>(j,i)= 255;
		}
		else if (image.channels() == 3) { // color image
			image.at<cv::Vec3b>(j,i)[0]= 255;
			image.at<cv::Vec3b>(j,i)[1]= 255;
			image.at<cv::Vec3b>(j,i)[2]= 255;
		}
	}

}