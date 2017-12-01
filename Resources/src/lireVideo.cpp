//
//  lireVideo.cpp
//  INF4710_TP3
//
//  Created by Wilfried Kamga on 2017-11-20.
//  Copyright © 2017 Wilfried Kamga. All rights reserved.
//

#include "common.hpp"
using namespace tp3;

vector<cv::Mat> tp3::lireVideo(const string nomFichier) {
    
    cv::VideoCapture cap(nomFichier);
    vector<cv::Mat> frames;
    if(cap.isOpened()){  // check if we succeeded
        while(true) {
            cv::Mat frame;
            cap >> frame; // get a new frame from video
            if(frame.empty())
                break; // end-of-stream
            frames.push_back(frame);
            //cv::imshow("frame",frame);
            //cv::waitKey(1);
        }
    }
    return frames;
}
