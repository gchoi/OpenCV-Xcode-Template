#include "stdafx.h"
#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

/** @function main */
int main( int argc, char** argv )
{

	// Read an image
	cv::Mat image = cv::imread( "../res/gchoi.jpg", 1 );

	int nRow = image.rows;
    int nCol = image.cols;
    
    // change colors
    cv::string tmp1, tmp2, filename;
    tmp1 = "../img/";
    tmp2 = ".jpg";
    
    int step = 0;
    int cnt = 0;
    
    while( step < nCol - 20 ) {
        cv::Mat image = cv::imread( "../res/gchoi.jpg", 1 );
        
        for( int i = 0 ; i < nRow ; i++ ) {
            
            int gray = (int)( 255/(150 - 1) * i );
            
            for( int j = step ; j < step + 20 ; j++ ) {
                image.at<cv::Vec3b>(i,j)[0]= gray;
                image.at<cv::Vec3b>(i,j)[1]= gray;
                image.at<cv::Vec3b>(i,j)[2]= gray;
            }
        }
        
        filename = tmp1 + std::to_string(cnt) + tmp2;
        
        cv::imwrite(filename, image);
        
        step += 20;
        cnt++;
    }

	return 0;
}