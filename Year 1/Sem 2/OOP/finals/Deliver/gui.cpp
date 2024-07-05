//
// Created by Bob on 6/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include "Service.h"
#include "utils.h"

gui::gui(Service &service, Courier &courier): service{service}, courier{courier}, ui(new Ui::gui) {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(courier.getName()));
    this ->setWindowTitle(QString::fromStdString(courier.getName()));
    string labelText = "Zone: " + to_string(courier.getZone().x) + " " + to_string(courier.getZone().y) + " " + to_string(courier.getZone().r);

    this -> ui->zoneLabel->setText(QString::fromStdString(labelText));
    this->populateList();

    fillComboBox();

    QObject::connect(this -> ui->streetComboBox, &QComboBox::currentTextChanged, this, &gui::filterByComboBox);
    QObject::connect(this -> ui->deliverButton, &QPushButton::clicked, this, &gui::deliverPackage);
}
void gui::populateList() {
    ui->packageListView->clear();

    for(auto package: this->courier.getPackages()){
        Package p = *package;
        if(p.getDeliveryStatus() == "false") {
            QString item = QString::fromStdString(p.toString());
            ui->packageListView->addItem(item);
        }
    }
}
gui::~gui() {
    delete ui;
}

void gui::fillComboBox() {
    ui->streetComboBox->clear();
    ui->streetComboBox->addItem("undelivered");

    for(auto streets: this->courier.getStreets()) {
        QString item = QString::fromStdString(streets);
        ui->streetComboBox->addItem(item);
    }
}

void gui::filterByComboBox() {
    string text = this -> ui->streetComboBox->currentText().toStdString();

    if(text == "undelivered") {
        this->populateList();
        return;
    }

    this -> ui->packageListView->clear();

    for(auto p : this->courier.getPackages()) {
        Package package = *p;
        if(package.getStreet() == text) {
            QString item = QString::fromStdString(package.toString());
            this->ui->packageListView->addItem(item);
        }
    }

}

void gui::deliverPackage() {
    int index = this->ui->packageListView->currentIndex().row();

    if(index < 0) {
        return;
    }

    Package* p = this->courier.getPackages()[index + 1];

    p->makeDelivery();
    service.saveToFile();

    service.notify();

}

void gui::update() {
    this -> populateList();
    this -> filterByComboBox();
}
