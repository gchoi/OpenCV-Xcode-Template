//
//  main.cpp
//  opencv-xcode-template
//
//  Created by gchoi on 31/03/15.
//  Copyright (c) 2015 gchoi. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // Read an image
    cv::Mat image = cv::imread("../../../../../res/gchoi_blurred.png");
    
    int nRow = image.rows;
    int nCol = image.cols;
    
    if( nRow == 0 && nCol == 0 )
        return 0;
    
    uchar *blue, *green, *red;
    
    // get (j, i) pixel
    int i = 1;
    int j = 0;
    
    if( i > nCol || j > nRow ) return 0;
    
    blue	= image.data + j*image.step + i*image.elemSize() + 0;
    green	= image.data + j*image.step + i*image.elemSize() + 1;
    red     = image.data + j*image.step + i*image.elemSize() + 2;
    
    std::cout << "Red: " << (int)*red << " , Green: " << (int)*green << " , Blue: " << (int)*blue << std::endl;
    
    
    return 0;
}