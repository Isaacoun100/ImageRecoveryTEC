//
// Created by michael on 18/10/21.
//

/**
 * @file ImageRecoveryGUI.h
 * @author Michael Valverde Navarro
 * @brief Clase que funciona para interfaz gráfica y muestra las imagenes generadas
 * @version 1.0
 * @date 18/10/2021
 */


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
    /**
     * @brief constructor de la clase ImageRecoveryGUI
     */
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

    /**
     *@brief establece los botones de la interfaz gŕafica
     */
    void setUpButtons();

    /**
     * @brief establece los labels para la interfaz gŕafica
     */
    void setUpLabels();

    /**
     * @brief establece un entry para ingresar texto en la interfaz gráfica
     */
    void setUpEntry();

    /**
     * @brief establece todos los widgets de la interfaz gráfica
     */
    void setUpWidgets();

public slots:
    /**
     * @brief método que se ejecuta cuando el boton Run es tocado, permite ejecutar el algoritmo
     */
    void clickedSlot();
    /**
     * @brief método que se ejecuta cuando el boton Next, permite visualizar la siguiente imagen generada
     */
    void clickedNextButton();

    /**
     * @brief método que se ejecuta cuando el botón Añadir imagen es tocado, permite abrir una ventana para seleccionar la imagen a aplicar el algoritmo
     */
    void clickedAddImage();
};

#endif //IMAGERECOVERYTEC_IMAGERECOVERYGUI_H
