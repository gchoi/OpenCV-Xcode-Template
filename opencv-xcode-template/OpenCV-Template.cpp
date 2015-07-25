#include "stdafx.h"
#include "opencv2/opencv.hpp"


int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image = cv::imread("../res/Lenna.png");

	cv::namedWindow("My Image");

	if( ( image.rows != 0 ) || ( image.cols != 0 ) ) {
		cv::imshow("My Image", image);
	}

	cv::waitKey(5000);

	return 0;
}