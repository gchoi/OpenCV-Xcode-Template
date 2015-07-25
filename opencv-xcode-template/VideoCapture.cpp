#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <stdlib.h>

using namespace cv;

//////////////////////////////////////////////////////////////////
// function : main
int main( int argc, char** argv )
{
	const string source = "../res/CamTrack.mp4";

	VideoCapture inputVideo( source );
    
	if ( !inputVideo.isOpened() )
    {
        std::cout  << "Could not open the input video: " << source << std::endl;
        return -1;
    }



    
    return 0;
}