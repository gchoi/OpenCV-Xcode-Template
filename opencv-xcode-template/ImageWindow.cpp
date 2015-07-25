#include "stdafx.h"
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

void GetPixelData( cv::Mat image, uchar* blue, uchar* green, uchar* red, int j, int i );

/** @function main */
int main( int argc, char** argv )
{
	// Read an image
	cv::Mat image = cv::imread( "../res/landscape.jpg", 1 );
	
	uchar *blue, *green, *red;

	blue = nullptr;
	green = nullptr;
	red = nullptr;

	// get (j,i) pixel : j-th row, i-th column pixel
	int j = 0;
	int i = 1;

	GetPixelData( image, blue, green, red, j, i );

	return 0;
}


/** @function GetPixelData (j,i) */
void GetPixelData( cv::Mat image, uchar* blue, uchar* green, uchar* red, int j, int i )
{
	uchar *data = image.data;

	int nRow = image.rows;
	int nCol = image.cols;

	if( i > nCol - 1 || j > nRow - 1 ) {
		cout << "Selected pixel is out of range." << endl;
		return;
	}

	blue	= image.data + j*image.step + i*image.elemSize() + 0;
	green	= image.data + j*image.step + i*image.elemSize() + 1;
	red		= image.data + j*image.step + i*image.elemSize() + 2;

	cout << "Red: " << (int)*red << " , Green: " << (int)*green << " , Blue: " << (int)*blue << endl;
}
