//
//  main.cpp
//  INF4710_TP3
//
//  Created by Wilfried Kamga on 2017-11-20.
//  Copyright © 2017 Wilfried Kamga. All rights reserved.
//

#include "common.hpp"

int main(int argc, char** argv)
{
    const string nomFichier = DATA_ROOT_PATH"INF4710_TP3_A2017_video_mpeg4.avi";
    vector<cv::Mat> frames;
    cv::VideoCapture cap(nomFichier);
    if (!cap.isOpened())  // check if we succeeded
        return -1;
    while(true){
        cv::Mat frame;
        cap >> frame; // get a new frame from video
        if (frame.empty())
            break; // end-of-stream
        
        cv::Mat_<float> Sx(3, 3);
        cv::Mat_<float> Sy(3, 3);
        vector<cv::Mat_<unsigned char>> aretes;
        vector<cv::Mat_<unsigned char>> aretesDilate;
        Sx = (cv::Mat_<float>(3, 3) << 1, 0, -1, 2, 0, -2, 1, 0, -1);
        Sy = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
        cv::Mat_<cv::Vec3f> Gx = tp3::calcConvo(frame, Sx);
        cv::Mat_<cv::Vec3f> Gy = tp3::calcConvo(frame, Sy);
        cv::Mat_<cv::Vec3f> matForce = tp3::calculerForce(Gx, Gy);
        cv::Mat_<unsigned char> areteMat = tp3::calcArete(matForce, SEUILARETE);
        aretes.push_back(areteMat);
        cv::Mat_<unsigned char> imageBinaireDilate;
        cv::dilate(areteMat, imageBinaireDilate, cv::Mat());
        aretesDilate.push_back(imageBinaireDilate);
    }
    

    return 0;
}



