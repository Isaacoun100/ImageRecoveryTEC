#include <iostream>
#include "XML/ReadWrite.h"
#include "image/ImageManager.h"
#include "logic/HexGeneticAlgo.h"

void print(vector <string> const &a) {
    cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        cout << a.at(i) << ' ';
}

int main() {

    /*
    ReadWrite readWrite;
    ImageManager imageManager;
    print(imageManager.getImageMatrix(readWrite.readFile("image/gen1.ppm")));
    cout<< "data here" <<to_string(readWrite.readFile("image/gen1.ppm").at(14)=='\n')<<"data here"<<endl;
     */

    HexGeneticAlgo hexGeneticAlgo;
    hexGeneticAlgo.startGeneticAlgo();

    return 0;

}