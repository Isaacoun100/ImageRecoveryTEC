#ifndef IMAGERECOVERYTEC_GENETICALGORITHM_H
#define IMAGERECOVERYTEC_GENETICALGORITHM_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

struct Member;
struct Population;

class GeneticAlgorithm {
public:
    GeneticAlgorithm();
    string stringToBin(string text);
    string invert(string text);
    char binToChar(string str);
    string binToString(string bin);
private:
};

#endif
