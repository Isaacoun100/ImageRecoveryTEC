#ifndef IMAGERECOVERYTEC_HEXGENETICALGO_H
#define IMAGERECOVERYTEC_HEXGENETICALGO_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

#include "../image/ImageManager.h"
#include "../XML/ReadWrite.h"

using namespace std;

struct Member;
struct Population;

class HexGeneticAlgo {
public:
    HexGeneticAlgo();
    void startGeneticAlgo();
    void setTarget(string hexa);

    //Decimal ←→ Hex
    string decToHex(int dec, int ceros);
    int hexToDec(string hexa);
    //Decimal ←→ Hex

private:
    void populateFromImage();
    void randomizePopulation();
    //The hex we're looking at
    string target;

    //Decimal ←→ Hex

    //Decimal ←→ Hex

    //Binary ←→ Hex
    string hexToBin(string hexa);
    string binToHex(string bin);
    //Binary ←→ Hex

    //Decimal ←→ Bin
    string decToBin(int dec);
    int binToDec(string bin);
    //Decimal ←→ Hex

    //Genetic Operations
    string mutate(string hexa);
    string invert(string hexa);
    //Genetic Operations.
};


#endif //IMAGERECOVERYTEC_HEXGENETICALGO_H
