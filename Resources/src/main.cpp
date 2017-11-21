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
    const char nomFichier[] = DATA_ROOT_PATH"INF4710_TP3_A2017_video.avi";
    tp3::lireVideo(nomFichier);

    return 0;
}



