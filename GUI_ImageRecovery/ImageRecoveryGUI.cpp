//
// Created by michael on 18/10/21.
//

#include "ImageRecoveryGUI.h"
#include <iostream>
using namespace std;


ImageRecoveryGUI::ImageRecoveryGUI() {

    window.resize(1000,550);
    window.setWindowTitle(QApplication::translate("toplevel","Top-level widget"));
    window.setFixedSize(window.size().width(),window.size().height());
    window.show();

    setUpWidgets();
}

ImageRecoveryGUI::~ImageRecoveryGUI() {

}

void ImageRecoveryGUI::setUpButtons() {

    buttonNext = new QPushButton(QApplication::translate("childwidget","Next"), &window);
    buttonNext->move(900,500);
    buttonNext->show();

    buttonPrevious = new QPushButton(QApplication::translate("childwidget","Previous"), &window);
    buttonPrevious->move(400,500);
    buttonPrevious->show();

    buttonAddImage = new QPushButton(QApplication::translate("childwidget","Add Image"), &window);
    buttonAddImage->move(200,150);
    buttonAddImage->show();

    buttonRun = new QPushButton(QApplication::translate("childwidget","Run"), &window);
    buttonRun->move(200,250);
    buttonRun->show();

    QObject::connect(buttonRun,SIGNAL(clicked()),this,SLOT(clickedSlot()));

}

void ImageRecoveryGUI::setUpLabels() {

    labelGenerations = new QLabel(QApplication::translate("childwidget","Number of generations to create: "),&window);
    labelGenerations->move(10,100);
    labelGenerations->show();

    labelImage = new QLabel(QApplication::translate("childwidget","Image goes here"),&window);
    labelImage->move(600,250);
    labelImage->show();

    labelImageCaption = new QLabel(QApplication::translate("childwidget","Generation #..."),&window);
    labelImageCaption->move(600,400);
    labelImageCaption->show();

}

void ImageRecoveryGUI::setUpEntry() {

    inputGenerations = new QLineEdit(QApplication::translate("childwidget",""),&window);

    inputGenerations->move(220,100);
    inputGenerations->resize(50,inputGenerations->size().height()-10);
    inputGenerations->show();
}

void ImageRecoveryGUI::setUpWidgets() {

    setUpButtons();
    setUpEntry();
    setUpLabels();
}

void ImageRecoveryGUI::clickedSlot() {
    cout << "Running program" << endl;

}


