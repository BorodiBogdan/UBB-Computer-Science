//
// Created by Bob on 5/9/2024.
//
#include <iostream>
#include "src/gui/mainwindow.h"
#include "src/gui/Connecter.h"

using namespace  std;

int main(int argc, char **argv){
    QApplication app(argc, argv);

    Service service;

    mainWindow w(nullptr, service);
    Connecter c(&w);
    c.connectAll();

    w.show();

    return app.exec();
}