//
//  calcArete.cpp
//  main
//
//  Created by Wilfried Kamga on 2017-11-30.
//

#include "common.hpp"
using namespace tp3;

cv::Mat calcArete(cv::Mat_<cv::Vec3f> force, float seuil)
{
    CV_Assert(!force.empty() && force.type() == CV_32FC3 && force.isContinuous());
    cv::Mat arete(force.size(), CV_8UC1);
    for (int i = 0; i < force.rows; i++)
    {
        for (int j = 0; j < force.cols; j++)
        {
            float temp;
            if (force.at<cv::Vec3f>(i, j)[0] >= force.at<cv::Vec3f>(i, j)[1])
                temp = force.at<cv::Vec3f>(i, j)[0];
            else
                temp = force.at<cv::Vec3f>(i, j)[1];
            if (force.at<cv::Vec3f>(i, j)[2] >= temp)
                temp = force.at<cv::Vec3f>(i, j)[2];
            
            if (temp > seuil)
                arete.at<unsigned char>(i, j) = 255;
            else
                arete.at<unsigned char>(i, j) = 0;
        }
    }
    return arete;
}
