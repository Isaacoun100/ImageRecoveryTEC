#ifndef IMAGERECOVERYTEC_HEXGENETICALGO_H
#define IMAGERECOVERYTEC_HEXGENETICALGO_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

struct Member;
struct Population;

class HexGeneticAlgo {
public:
    HexGeneticAlgo();
    void setTarget(string hex);
private:

    void randomizePopulation();
    //The hex we're looking at
    string target;
    //Decimal ←→ Hex
    string decToHex(int dec);
    int hexToDec(string hex);
    //Decimal ←→ Hex

    //Binary ←→ Hex
    string hexToBin(string hex);
    string binToHex(string bin);
    //Binary ←→ Hex

    //Decimal ←→ Bin
    string decToBin(int dec);
    int binToDec(string bin);
    //Decimal ←→ Hex

    //Genetic Operations
    string mutate(string hex);
    string invert(string hex);
    //Genetic Operations.
};


#endif //IMAGERECOVERYTEC_HEXGENETICALGO_H
