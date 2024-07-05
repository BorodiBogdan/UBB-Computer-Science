#include <QApplication>
#include <QDebug>
#include <QListWidget>
#include <QLabel>
#include "mainwindow.h"
#include "test.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    testGetCarsByManufacturer();

    mainWindow w;
    w.show();

    return app.exec();
}
