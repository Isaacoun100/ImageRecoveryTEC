//
// Created by michael on 18/10/21.
//

#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QString>

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
    QLabel *labelSavedImage;

    QString fileChooser;


    void setUpButtons();
    void setUpLabels();
    void setUpEntry();
    void setUpWidgets();

public slots:
    void clickedSlot();
    void clickedNextButton();
    void clickedAddImage();
};

#endif //IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
