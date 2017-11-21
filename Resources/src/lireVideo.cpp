//
//  lireVideo.cpp
//  INF4710_TP3
//
//  Created by Wilfried Kamga on 2017-11-20.
//  Copyright © 2017 Wilfried Kamga. All rights reserved.
//

#include "common.hpp"
using namespace tp3;

int tp3::lireVideo(const char* nomFichier) {
    cv::VideoCapture cap(nomFichier);
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    while(true) {
        cv::Mat frame;
        cap >> frame; // get a new frame from video
        if(frame.empty())
            break; // end-of-stream
        cv::imshow("frame",frame);
        cv::waitKey(1);
    }
    return 0;
}
