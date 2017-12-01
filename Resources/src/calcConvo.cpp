//
//  calcConvo.cpp
//  main
//
//  Created by Wilfried Kamga on 2017-12-01.
//

#include "common.hpp"
using namespace tp3;

cv::Mat_<cv::Vec3f> calcConvo(const cv::Mat& image, const cv::Mat_<float>& noyau)
{
    CV_Assert(!image.empty());
    CV_Assert(image.type() == CV_8UC3);
    CV_Assert(image.isContinuous());
    CV_Assert(!noyau.empty() && noyau.isContinuous());
    cv::Mat gradients(image.size(), CV_32FC3, cv::Scalar_<float>(0.0f));
    
    int distAuCentreKernel = noyau.rows / 2;
    for (int canal = 0; canal < image.channels(); canal++)
    {
        for (int ligne = distAuCentreKernel; ligne < image.rows - distAuCentreKernel; ligne++)
        {
            for (int colonne = distAuCentreKernel; colonne < image.cols - distAuCentreKernel; colonne++)
            {
                tp3::appliquerFiltre(image, gradients, noyau, ligne, colonne, canal);
            }
        }
    }
    
    return gradients;
}
