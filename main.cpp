#include <iostream>
#include "XML/ReadWrite.h"
#include "image/ImageManager.h"
#include "logic/HexGeneticAlgo.h"
#include "XML/ReadWrite.h"

void print(vector <string> const &a) {
    cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
}

int main() {
    ReadWrite readWrite;

    HexGeneticAlgo hexGeneticAlgo;
    hexGeneticAlgo.startGeneticAlgo();

    ImageManager imageManager;
    vector<string> list=imageManager.getImageMatrix(readWrite.readFile("image/ti1.ppm"));

    print(list);

    imageManager.randomImage("image/ti1");

    return 0;

}