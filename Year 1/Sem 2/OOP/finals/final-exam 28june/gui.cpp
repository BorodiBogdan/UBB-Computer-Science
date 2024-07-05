//
// Created by Bob on 6/27/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"


gui::gui(Service &serv, Courier &courier) : service(serv), courier(courier), ui(new Ui::gui){
    this -> ui->setupUi(this);
    this ->setWindowTitle(QString::fromStdString(courier.getName()));

    for(auto package : serv.getPackages()){
        QString item = QString::fromStdString(package.toString());
        this -> ui->DeliverylistWidget->addItem(item);
    }
}

gui::~gui() {
    delete ui;
}

void gui::update() {
    return;
}
