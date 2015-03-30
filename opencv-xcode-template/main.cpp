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
    cv::Mat image = cv::imread("../../../../../res/lenna.png");
    
    int nRow = image.rows;
    int nCol = image.cols;
    
    std::cout << "nRow : " << nRow << std::endl;
    std::cout << "nCOl : " << nCol << std::endl;
    
    if( nRow == 0 && nCol == 0 )
        return 0;
    
    // Set name of the window
    cv::namedWindow("My Image");
    
    // Show the window
    cv::imshow("My Image", image);
    
    cv::waitKey(5000);
    
    return 0;
}
