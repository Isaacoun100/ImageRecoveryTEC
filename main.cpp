#include <iostream>
#include <QtWidgets>
#include "GUI_ImageRecovery/ImageRecoveryGUI.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc,argv);
    //QWidget window;
    //window.resize(320,240);
    //window.setWindowTitle(QApplication::translate("toplevel","Top-level widget"));
    //window.show();

    //QPushButton *button = new QPushButton(QApplication::translate("childwidget","Button One"), &window);
    //button->move(100,100);
    //button->show();

    ImageRecoveryGUI GUI;

    return app.exec();
}
