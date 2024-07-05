#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainWindow w;
    w.show();

    return QApplication::exec();
}
