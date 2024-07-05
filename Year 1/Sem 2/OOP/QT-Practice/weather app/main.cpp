//
// Created by Bob on 5/28/2024.
//
#include <QApplication>
#include "mainwindow.h"
#include <QPushButton>

int main(int argc, char **argv){
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return  app.exec();
}