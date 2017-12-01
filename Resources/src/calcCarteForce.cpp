//
//  calcCarteForce.cpp
//  INF4710_TP3
//
//  Created by Wilfried Kamga on 2017-11-20.
//  Copyright © 2017 Wilfried Kamga. All rights reserved.
//

#include "common.hpp"
using namespace tp3;

cv::Mat_<cv::Vec3f> calculerForce(const cv::Mat_<cv::Vec3f>& Gx, const  cv::Mat_<cv::Vec3f>& Gy){
    CV_Assert(!Gx.empty() && Gx.type() == CV_32FC3 && Gx.isContinuous());
    CV_Assert(!Gy.empty() && Gy.type() == CV_32FC3 && Gy.isContinuous());
    cv::Mat force(Gx.size(), CV_32FC3);
    int nbrCanaux = Gx.channels();
    for(int i = 0; i < nbrCanaux; i++){
        for(int m = 0; m < force.rows; m++){
            for(int n = 0; n < force.cols; n++){
                float v1 = Gx.at<cv::Vec3f>(m, n)[i];
                float v2 = Gy.at<cv::Vec3f>(m, n)[i];
                force.at<cv::Vec3f>(m, n)[i] = cv::sqrt(cv::pow(v1, 2) + cv::pow(v2, 2));
            }
        }
    }
    return force;
}


