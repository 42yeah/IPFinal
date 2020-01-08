//
//  main.cpp
//  IPFinal
//
//  Created by apple on 2020/1/7.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include <iostreasssm>
#include <opencv2/opencv.hpp>


int main(int argc, const char * argv[]) {
    cv::Mat frame;
    cv::VideoCapture capture;
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    capture.open(deviceID + apiID);
    while (true) {
        capture.read(frame);
        cv::imshow("Capture", frame);
        if (cv::waitKey(5) >= 0) {
            break;
        }
    }
    std::cout << "Done" << std::endl;
    return 0;
}
