//
// Created by Bob on 5/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"
#include <QDebug>

mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    this -> populateListView();

    QObject::connect(this ->ui->showCarsButton, &QPushButton::clicked, this, &mainWindow::getCarsByManufacturer);
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::populateListView() {
    int row = 0;
    for(auto car : this -> service.getCars()){
        string labelText = car.getMnufacturer() + " | " + car.getModel();
        QString label = QString::fromStdString(labelText);

        this -> ui->carListWidget->addItem(label);

        QListWidgetItem *item = ui->carListWidget->item(row);
        item->setForeground(QColor(QString::fromStdString(car.getColor())));


        QFont f;
        f.setBold(0);

        item->setFont(f);
        row++;
    }
}

void mainWindow::getCarsByManufacturer() {
    string text = this->ui->manufacturerLineEdit->text().toStdString();
    this->ui->manufacturerLineEdit->clear();

    string labelText = "";
    string finalText = "";
    finalText = to_string(this -> service.getCarsByManufacturer(text).size()) + "\n";

    ui->listWidgetForManufacturer->clear();
    this -> ui->listWidgetForManufacturer->addItem(QString::fromStdString(to_string(this->service.getCarsByManufacturer(text).size())));

    for (auto car: this->service.getCarsByManufacturer(text)) {
        string labelText = car.getModel() + " | " + car.getMnufacturer() + " | " + to_string(car.getYearOfFabrication()) + " | " + car.getColor();
        QString l = QString(QString::fromStdString(labelText));
        this -> ui->listWidgetForManufacturer->addItem(l);

        finalText += labelText + "\n";
    }
    this -> ui->manufacturerLabel->setText(QString::fromStdString(finalText));
}
