//
//  appliquerFiltre.cpp
//  main
//
//  Created by Wilfried Kamga on 2017-12-01.
//

#include <stdio.h>
#include "common.hpp"
using namespace tp3;

void appliquerFiltre(const cv::Mat& image, cv::Mat& gradients, const cv::Mat_<float>& noyau,
                          const int ligneDest, const int colonneDest, const int canal)
{
    gradients.at<cv::Vec3f>(ligneDest, colonneDest)[canal] = 0;
    int distance = noyau.rows / 2;
    int ligImg = (-1) * distance;
    for (int ligne = 0; ligne < noyau.rows; ligne++)
    {
        int colImg = (-1) * distance;
        for (int colonne = 0; colonne < noyau.cols; colonne++)
        {
            int vraiColImg = colImg + colonneDest;
            int vraiLigImg = ligImg + ligneDest;
            gradients.at<cv::Vec3f>(ligneDest, colonneDest)[canal] += image.at<cv::Vec3b>(vraiLigImg, vraiColImg)[canal]
            * noyau.at<float>(ligne, colonne);
            colImg++;
        }
        ligImg++;
    }
}
