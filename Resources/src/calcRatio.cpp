//
//  calcRatio.cpp
//  main
//
//  Created by Wilfried Kamga on 2017-12-01.
//

#include "common.hpp"
using namespace tp3;

float calcRatio(const cv::Mat& imgBinaireDilate, const cv::Mat& imgBinaire)
{
    CV_Assert(!imgBinaire.empty() && imgBinaireDilate.type() == CV_8UC1 && imgBinaireDilate.isContinuous());
    CV_Assert(!imgBinaire.empty() && imgBinaire.type() == CV_8UC1 && imgBinaire.isContinuous());
    
    float resultat, multiDilateEdge = 0, sommeEdge = 0;
    
    for (int ligne = 0; ligne < imgBinaireDilate.rows; ligne++)
    {
        for (int colonne = 0; colonne < imgBinaireDilate.cols; colonne++)
        {
            int valeurDilatee = imgBinaireDilate.at<unsigned char>(ligne, colonne);
            int valeurEdge    = imgBinaire.at<unsigned char>(ligne, colonne);
            
            if (valeurDilatee == 255)
                valeurDilatee = 1;
            if (valeurEdge == 255)
                valeurEdge = 1;
            
            multiDilateEdge += valeurDilatee * valeurEdge;
            sommeEdge += valeurEdge;
        }
    }
    
    resultat = 1 - (multiDilateEdge / sommeEdge);
    return resultat;
}
