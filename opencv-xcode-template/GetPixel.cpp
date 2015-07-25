#include "stdafx.h"
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

/* @ function main */
int main( int argc, char** argv )
{
	// Read an image
	cv::Mat image = cv::imread( "../res/gchoi.jpg", 1 );

	// get (j,i) pixel : j-th row, i-th column pixel
	int j = 0;
	int i = 1;

	// read a pixel from image directly
	int nBlue, nGreen, nRed;
	nBlue = 0; nGreen = 0; nRed = 0;

	nBlue	= image.at<cv::Vec3b>(j,i)[0];
	nGreen	= image.at<cv::Vec3b>(j,i)[1];
	nRed	= image.at<cv::Vec3b>(j,i)[2];

	cout << "Red : " << nRed << " , Green : " << nGreen << " , Blue : " << nBlue << endl;

	return 0;
}