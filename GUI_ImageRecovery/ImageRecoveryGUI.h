//
// Created by michael on 18/10/21.
//

#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
using namespace std;

#ifndef IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
#define IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
class ImageRecoveryGUI:public QMainWindow{
    Q_OBJECT
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
    QLabel *labelImage;
    QLabel *labelImageCaption;


    void setUpButtons();
    void setUpLabels();
    void setUpEntry();
    void setUpWidgets();

public slots:
    void clickedSlot();
};

#endif //IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
