#ifndef IMAGERECOVERYTEC_IMAGEMANAGER_H
#define IMAGERECOVERYTEC_IMAGEMANAGER_H

#include "../logic/HexGeneticAlgo.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class ImageManager {
public:

    ImageManager();
    void WriteOnImage(vector<string> newList, string text);
    vector<string> getImageMatrix(string imageText);
    void randomImage(string text);
private:
    vector<string> rgbToHex(vector<int> vectorRGB);
    vector<string> getListHex();
    void generateImage(string text, int iteration);
};


#endif
