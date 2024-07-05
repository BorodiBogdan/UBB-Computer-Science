#include <iostream>
#include "mainwindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char **argv){
    QApplication my_app = QApplication(argc, argv);
    MainWindow w;
    w.show();

    return my_app.exec();
}