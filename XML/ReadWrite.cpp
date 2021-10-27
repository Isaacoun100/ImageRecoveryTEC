#include "ReadWrite.h"

/**
 * This method will write the contents of the string result variable into the tmp.txt file that will contain the XML
 * information about the present and past generations
 * @param result the string that contains the data that is going to be written.
 */
void ReadWrite::writeFile(string result) {

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+"generations/temp.xml";

    ofstream path(temporal);

    if(path.fail()){
        cout << "Unable to locate file to write " << endl;
    }

    path<<result;
    path.close();
}

/**
 * This method will read all of the contents of the temp.txt file that will contain the XML information about the
 * present and past generations
 * @return a string containing the data in the tmp.txt
 */
string ReadWrite::readFile() {
    string text;

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+"generations/temp.xml";

    ifstream path(temporal);

    if(path.fail()){
        cout << "Unable to locate file to read " << endl;
        return text;
    }

    getline(path,text);

    path.close();
    return text;
}

/**
 * This method clears all contents in the temporal file that will contain the XML information about the present and
 * past generations
 */
void ReadWrite::clearFile() {
    writeFile("");
}
