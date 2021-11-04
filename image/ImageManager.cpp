#include "ImageManager.h"

ImageManager::ImageManager() {
    srand(time(nullptr));
    ofstream image;
    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+"image/ti1.ppm";
    image.open(temporal);
    if(image.is_open()){
        image<<"P3"<<endl;
        image<<"250 250"<<endl;
        image<<"255"<<endl;

        for(int y=0; y<250;y++){
            for(int x=0;x<250;x++){
                image << rand()%255 << " " << rand()%255 << " " << rand()%255 <<endl;
            }
        }
    }
    image.close();
}
