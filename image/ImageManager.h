#ifndef IMAGERECOVERYTEC_IMAGEMANAGER_H
#define IMAGERECOVERYTEC_IMAGEMANAGER_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include <unistd.h>

using namespace std;

class ImageManager {
public:
    ImageManager();
private:
    void generateImage(string text, int iteration);
    void randomImage();
};


#endif
