#include "ReadWrite.h"

/**
 * This method will write the contents of the string result variable into the tmp.txt file that will contain the XML
 * information about the present and past generations
 * @param result the string that contains the data that is going to be written.
 */
void ReadWrite::writeFile(string path, string result) {

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+result;

    ofstream stream(temporal);

    if(stream.fail()){
        cout << "Unable to locate file to write " << endl;
    }

    stream<<result;
    stream.close();
}

/**
 * This method will read all of the contents of the temp.txt file that will contain the XML information about the
 * present and past generations
 * @return a string containing the data in the tmp.txt
 */
string ReadWrite::readFile(string path) {
    string text, result;

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+path;

    ifstream stream(temporal);

    if(stream.fail()){
        cout << "Unable to locate file to read " << endl;
        return text;
    }

    if (stream.is_open()){
        while ( getline (stream, text) ){
            result.append(text +'\n');
        }
    }

    //getline(stream,text);

    stream.close();
    return result;
}

/**
 * This method clears all contents in the temporal file that will contain the XML information about the present and
 * past generations
 */
void ReadWrite::clearFile(string path) {
    writeFile(path,"");
}
