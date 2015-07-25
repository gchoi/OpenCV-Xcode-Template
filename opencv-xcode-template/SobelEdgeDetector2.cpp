#include "stdafx.h"
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

#define KERNEL_SIZE_ROWS	3
#define KERNEL_SIZE_COLS	3

/* @ function main */
int main( int argc, char** argv )
{
	cv::Mat src, src_gray;
	cv::Mat grad;

	/// Load an image
	src = cv::imread( "../res/steam_engine.png", 1 );

	if( !src.data ) { return -1; }

	/// Sobel kernel - Gradient X
	float fKernelX[KERNEL_SIZE_ROWS][KERNEL_SIZE_COLS];

	fKernelX[0][0] = -1.0f;
	fKernelX[0][1] = 0.0f;
	fKernelX[0][2] = 1.0f;

	fKernelX[1][0] = -2.0f;
	fKernelX[1][1] = 0.0f;
	fKernelX[1][2] = 2.0f;

	fKernelX[2][0] = -1.0f;
	fKernelX[2][1] = 0.0f;
	fKernelX[2][2] = 1.0f;

	/// Sobel kernel - Gradient Y
	float fKernelY[KERNEL_SIZE_ROWS][KERNEL_SIZE_COLS];

	fKernelY[0][0] = -1.0f;
	fKernelY[0][1] = -2.0f;
	fKernelY[0][2] = -1.0f;

	fKernelY[1][0] = 0.0f;
	fKernelY[1][1] = 0.0f;
	fKernelY[1][2] = 0.0f;

	fKernelY[2][0] = +1.0f;
	fKernelY[2][1] = +2.0f;
	fKernelY[2][2] = +1.0f;

	/// Convert it to gray
	cvtColor( src, src_gray, CV_RGB2GRAY );

	/// Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;
	cv::Mat grad_abs;

	///
	int nRows = src.rows;
	int nCols = src.cols;
	uchar charGray;
	int nGray;
	int nPixelValX;
	int nPixelValY;
	int nPixelValAbs;

	src_gray.copyTo( grad_x );
	src_gray.copyTo( grad_y );
	src_gray.copyTo( grad_abs );

	for( int j = 1 ; j < nRows - 2 ; j++ ) {

		for( int i = 1 ; i < nCols - 2 ; i++ ) {

			nPixelValX = 0;
			nPixelValY = 0;
			nPixelValAbs = 0;

			/// convolution
			for( int m = 0 ; m < 3 ; m++ ) {

				for( int k = 0 ; k < 3 ; k++ ) {

					charGray = src_gray.at<uchar>(j+(m-1), i+(k-1));
					nGray = (int)charGray;

					nPixelValX += nGray * (int)fKernelX[m][k];
					nPixelValY += nGray * (int)fKernelY[m][k];
					//nPixelValAbs += (int)( sqrt( powf( nPixelValX, 2.0f ) + powf( nPixelValY, 2.0f ) ) );
					nPixelValAbs += (int)( ( nPixelValX + nPixelValY ) / 2.0f );

					if( nPixelValX < 0 )		nPixelValX = 0;
					if( nPixelValX > 255 )		nPixelValX = 255;

					if( nPixelValY < 0 )		nPixelValY = 0;
					if( nPixelValY > 255 )		nPixelValY = 255;

					if( nPixelValAbs < 0 )		nPixelValAbs = 0;
					if( nPixelValAbs > 255 )	nPixelValAbs = 255;

				}

			}

			//
			grad_x.at<uchar>(j,i) = (uchar)nPixelValX;
			grad_y.at<uchar>(j,i) = (uchar)nPixelValY;
			grad_abs.at<uchar>(j,i) = (uchar)nPixelValAbs;

		}

	}

	/// Create window
	//cv::namedWindow( "Image Grayed", CV_WINDOW_AUTOSIZE );
	//cv::namedWindow( "Gradient X", CV_WINDOW_AUTOSIZE );
	//cv::namedWindow( "Gradient Y", CV_WINDOW_AUTOSIZE );
	cv::namedWindow( "Gradient Abs", CV_WINDOW_AUTOSIZE );

	
	/// Gradient X
	

	/// Gradient Y

	
	/// Show some stuff
	//cv::imshow( "Image Grayed", src_gray );
	//cv::imshow( "Gradient X", grad_x );
	//cv::imshow( "Gradient Y", grad_y );
	cv::imshow( "Gradient Abs", grad_abs );
	
	cv::waitKey(0);

	return 0;

}