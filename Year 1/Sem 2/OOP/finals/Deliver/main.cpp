//
// Created by Bob on 6/28/2024.
//
#include "gui.h"
#include "companyui.h"
#include <QApplication>
#include "plotorderswidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Service service;

    for(auto &courier : service.get_couriers()){
        gui *g = new gui(service, courier);
        service.addObserver(g);
        g -> show();
    }
    companyUi *c = new companyUi(service);
    service.addObserver(c);

    c -> show();

    plotOrdersWidget *p = new plotOrdersWidget(service);
    service.addObserver(p);

    p->show();

    return a.exec();
}