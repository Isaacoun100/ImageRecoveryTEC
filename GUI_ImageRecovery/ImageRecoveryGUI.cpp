//
// Created by michael on 18/10/21.
//

#include "ImageRecoveryGUI.h"


ImageRecoveryGUI::ImageRecoveryGUI() {

    window.resize(1000,550);
    window.setWindowTitle(QApplication::translate("toplevel","Top-level widget"));
    window.show();

    labelGenerations = new QLabel(QApplication::translate("childwidget","Number of generations to create: "),&window);
    labelGenerations->move(10,100);
    labelGenerations->show();

    inputGenerations = new QLineEdit(QApplication::translate("childwidget",""),&window);

    inputGenerations->move(220,100);
    inputGenerations->resize(50,inputGenerations->size().height()-10);
    inputGenerations->show();


    setUpButtons();
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

}
