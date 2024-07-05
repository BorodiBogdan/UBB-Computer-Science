//
// Created by Bob on 5/22/2024.
//
#include "gui/mainwindow.h"
#include <QApplication>
#include <QApplication>
using namespace  std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    mainWindow gui;
    gui.show();

    return app.exec();
}