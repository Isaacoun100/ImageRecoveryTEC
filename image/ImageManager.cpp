#include "ImageManager.h"

vector<int> listRGB = vector<int>(187500);
vector<string> listHex= vector<string>(20833);

/*
 * Return present working directory
 */
string getPWD(){
    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size());
    return temporal;
}

/**
 * Creates a random image with random colors
 * @param text
 */
void ImageManager::randomImage(string text) {
    string temporal = getPWD();
    string filename(temporal+text+".ppm");
    srand(time(nullptr));
    ofstream image;

    image.open(filename);
    if(image.is_open()){
        image<<"P3"<<endl;
        image<<"250 250"<<endl;
        image<<"255"<<endl;

        for(int y=0; y<250;y++){
            for(int x=0;x<250;x++){
                if(x<244 || y<244){
                    image << rand()%255 << " " << rand()%255 << " " << rand()%255 <<endl;
                }
                else{
                    image << 255 << " " << 255 << " " << 255 <<endl;
                }
            }
        }
    }
    image.close();
}

/**
 * Generates an image based on its input
 * @param text
 * @param iteration
 */
void ImageManager::generateImage(string text, int iteration) {
    string temporal = getPWD();
    string filename(temporal+text+ to_string(iteration)+".ppm");
    fstream output_fstream;

    output_fstream.open(filename, ios_base::out);
    if (!output_fstream.is_open()) cerr << "Failed to open " << filename << '\n';
    else cerr << "Done Writing!" << endl;
}


/**
 * Transforms the image into a matrix that contains the hex color value
 * @param imageText
 * @return
 */
vector<string> ImageManager::getImageMatrix(string imageText) {
    int count, value, imc=0;
    string tmp="";
    for(int i=0; i<imageText.size();i++){
        if(imageText.at(i)=='2' && imageText.at(i+1)=='5' && imageText.at(i+2)=='5'){
            count=i+4;
            i=imageText.size();
        }
    }

    for(int i=count; i<imageText.size();i++){
        if(imageText.at(i)!=' ' && imageText.at(i)!='\n' ){
            tmp+=imageText.at(i);
        }
        else{
            if(tmp!=""){
                value= stoi(tmp);
                listRGB.at(imc)=value;
                imc++;
                tmp="";
            }
        }
    }

    return rgbToHex(listRGB);
}

/**
 * Converts RGB values to Hex
 * @param vectorRGB
 * @return
 */
vector<string> ImageManager::rgbToHex(vector<int> vectorRGB) {
    int count=0, i=0;
    while(i<vectorRGB.size()-3){
        listHex.at(count)=
                HexGeneticAlgo().decToHex(vectorRGB.at(i),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+1),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+2),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+3),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+4),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+5),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+6),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+7),2)+
                HexGeneticAlgo().decToHex(vectorRGB.at(i+8),2);
        i+=9;
        count++;
    }

    return listHex;
}

/**
 * Constructor for the class
 */
ImageManager::ImageManager() {}

/*
 * Writes the given info into an image
 */
void ImageManager::WriteOnImage(vector<string> newList, string text){
    string result;

    string temporal = getPWD();
    string filename(temporal+text+".ppm");
    srand(time(nullptr));
    ofstream image;

    image.open(filename);
    if(image.is_open()){
        image<<"P3"<<endl;
        image<<"250 250"<<endl;
        image<<"255"<<endl;

        for(int i=0;i<newList.size();i++){
            image << HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(0)))+
                    HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(1)))
                    << " " <<
                    HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(2)))+
                    HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(3)))
                    << " " <<
                    HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(4)))+
                    HexGeneticAlgo().hexToDec(to_string(newList.at(i).at(5)))
                    <<endl;
        }

    }

}

/*
 * Returns the vector with its hex color values
 */
vector<string> ImageManager::getListHex() {
    return listHex;
}
