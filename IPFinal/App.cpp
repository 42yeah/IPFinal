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
    camera = Camera(0);
}

void App::start() { 
    while (true) {
        cv::Mat &mat = camera.read();
        cv::imshow("Cam", mat);
        if (cv::waitKey(5) != -1) {
            break;
        }
    }
}

