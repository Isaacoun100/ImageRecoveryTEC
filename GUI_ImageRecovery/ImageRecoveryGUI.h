//
// Created by michael on 18/10/21.
//

#include <iostream>
#include <QtWidgets>
#include <QObject>
using namespace std;

#ifndef IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
#define IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
class ImageRecoveryGUI{
public:
    ImageRecoveryGUI();

    virtual ~ImageRecoveryGUI();


private:
    QWidget window;
    QPushButton *buttonNext;
    QPushButton *buttonPrevious;
    QPushButton *buttonAddImage;
    QPushButton *buttonRun;

    QLabel *labelGenerations;
    QLineEdit *inputGenerations;

    void setUpButtons();
};

#endif //IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
