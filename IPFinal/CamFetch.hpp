//
//  CamFetch.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef CamFetch_hpp
#define CamFetch_hpp

#include <opencv2/opencv.hpp>


class Camera {
public:
    Camera() {}
    Camera(int id);
    
    cv::Mat &read();
    
private:
    cv::VideoCapture cap;
    cv::Mat buffer;
};

#endif /* CamFetch_hpp */
