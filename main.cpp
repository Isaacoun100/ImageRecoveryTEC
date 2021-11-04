#include <iostream>
#include "XML/ReadWrite.h"

int main() {
    ReadWrite readWrite;
    cout<< readWrite.readFile("image/ti1.ppm")<<endl;
    return 0;
}