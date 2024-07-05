//
// Created by Bob on 6/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_courierCompanyUi.h" resolved

#include "couriercompanyui.h"
#include "ui_courierCompanyUi.h"
#include <QDebug>

courierCompanyUi::courierCompanyUi(Service &s) : serv(s), ui(new Ui::courierCompanyUi){
    this -> ui->setupUi(this);
    this ->setWindowTitle("Company ui");

    QObject::connect(this -> ui->pushButton, &QPushButton::clicked, this, &courierCompanyUi::add);
}
courierCompanyUi::~courierCompanyUi() {
    delete ui;
}

void courierCompanyUi::update() {
    return;
}

void courierCompanyUi::add() {
    string name = this -> ui->lineEdit_2->text().toStdString();
    string location = this -> ui->lineEdit->text().toStdString();
    string street = this -> ui->lineEdit->text().toStdString();
    string status = this -> ui->lineEdit_4->text().toStdString();

    qDebug() << name << " " << location << " " << street << status;
}
