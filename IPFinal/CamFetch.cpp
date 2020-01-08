//
//  CamFetch.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "CamFetch.hpp"


Camera::Camera(int id) {
    cap.open(id + cv::CAP_ANY);
}

cv::Mat &Camera::read() {
    cap.read(buffer);
    return buffer;
}

void *Camera::getRawMemory() { 
    return &buffer.at<int>(0);
}

int Camera::getBufferWidth() {
    return buffer.cols;
}

int Camera::getBufferHeight() {
    return buffer.rows;
}

