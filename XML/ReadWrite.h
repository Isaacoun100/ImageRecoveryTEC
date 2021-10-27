//
// Created by arch-i3 on 26/10/21.
//

#ifndef IMAGERECOVERYTEC_READWRITE_H
#define IMAGERECOVERYTEC_READWRITE_H

#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * The ReadWrite class will read, write and clear an specific file that will contain the XML information about the
 * present and past generations
 */
class ReadWrite {
public:
    /**
     * This method clears all contents in the temporal file that will contain the XML information about the present and
     * past generations
     */
    void clearFile();

    /**
     * This method will read all of the contents of the temp.txt file that will contain the XML information about the
     * present and past generations
     * @return a string containing the data in the tmp.txt
     */
    string readFile();

    /**
     * This method will write the contents of the string result variable into the tmp.txt file that will contain the XML
     * information about the present and past generations
     * @param result the string that contains the data that is going to be written.
     */
    void writeFile(string result);
};


#endif

