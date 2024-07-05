//
// Created by Bob on 6/27/2024.
//
#include "gui.h"
#include <QApplication>
#include "couriercompanyui.h"

int main(int argc, char **argv){
    QApplication a(argc, argv);
    Service service;

    for(auto &s : service.getCouriers()){
        gui *ngui = new gui(service, s);
        ngui->show();
    }
    courierCompanyUi *c = new courierCompanyUi(service);

    c-> show();

    return a.exec();
}
