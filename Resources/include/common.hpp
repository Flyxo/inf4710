
#pragma once

#include "defines.hpp"

#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <memory>
#include <map>
#include <queue>
#include <map>
#include <string>
#include <array>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <numeric>
#include <iostream>
#include <exception>
#include <opencv2/opencv.hpp>

#ifdef _MSC_VER
#define PAUSE_EXIT(code) do {system("pause"); std::exit(code);} while(0)
#else //ndef(_MSC_VER)
#define PAUSE_EXIT(code) do {std::exit(code);} while(0)
#endif //ndef(_MSC_VER)

namespace tp3 {
    int lireVideo(const char* nomFichier);

    template<typename T, int nChannels=1>
    inline bool isEqual(const cv::Mat& a, const cv::Mat& b) {
        if(a.empty() && b.empty())
            return true;
        if(a.dims!=b.dims || a.size!=b.size || a.type()!=b.type())
            return false;
        CV_Assert(a.total()*a.elemSize()==b.total()*b.elemSize() && a.dims==2);
        for(int i=0; i<a.rows; ++i)
            for(int j=0; j<a.cols; ++j)
                for(int c=0; c<nChannels; ++c)
                    if(a.ptr<T>(i,j)[c]!=b.ptr<T>(i,j)[c])
                        return false;
        return true;
    }

    template<typename T, size_t nChannels=1>
    inline bool isNearlyEqual(const cv::Mat& a, const cv::Mat& b, double dMaxDiff) {
        if(a.empty() && b.empty())
            return true;
        if(a.dims!=b.dims || a.size!=b.size || a.type()!=b.type())
            return false;
        CV_Assert(a.total()*a.elemSize()==b.total()*b.elemSize() && a.dims==2);
        for(int i=0; i<a.rows; ++i)
            for(int j=0; j<a.cols; ++j)
                for(int c=0; c<nChannels; ++c)
                    if(std::abs(double(a.ptr<T>(i,j)[c])-double(b.ptr<T>(i,j)[c]))>dMaxDiff)
                        return false;
        return true;
    }

} // namespace tp3
