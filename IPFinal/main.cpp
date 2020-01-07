//
//  main.cpp
//  IPFinal
//
//  Created by apple on 2020/1/7.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>


int main(int argc, const char * argv[]) {
    cv::Mat mat;
    mat = cv::imread("Assets/Windmill.jpg");
    cv::imshow("Image", mat);
    cv::waitKey(0);
    return 0;
}
