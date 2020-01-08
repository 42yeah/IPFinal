//
//  App.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "App.hpp"
#include <opencv2/opencv.hpp>


void App::init() { 
    hardwareCamera = Camera(0);
}

void App::start() {
    while (true) {
        cv::Mat &mat = hardwareCamera.read();
        cv::imshow("Cam", mat);
        if (cv::waitKey(5) != -1) {
            break;
        }
    }
}

void App::testRawMemory() {
    hardwareCamera.read();
    char *buffer = (char *) hardwareCamera.getRawMemory();
    for (int i = 0; i < hardwareCamera.getBufferHeight(); i++) {
        for (int j = 0; j < hardwareCamera.getBufferWidth(); j++) {
            int offset = (i * hardwareCamera.getBufferWidth() + j) * 3;
            std::cout << "[" << (unsigned int) buffer[offset + 0] << ", " << (unsigned int) buffer[offset + 1] << ", " << (unsigned int) buffer[offset + 2] << "] ";
        }
        std::cout << std::endl;
    }
}