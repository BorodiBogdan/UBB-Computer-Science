//
// Created by Bob on 6/27/2024.
//
#include "gui.h"
#include <QApplication>

int main(int argc, char **argv){
    QApplication a(argc, argv);
    gui w;
    w.show();
    return a.exec();
    return 0;
}