#include <iostream>
#include <QtWidgets>
#include "GUI_ImageRecovery/ImageRecoveryGUI.h"
#include "dataStructures/CircularLinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    ImageRecoveryGUI GUI;
    return app.exec();
}
