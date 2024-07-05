//
// Created by Bob on 5/22/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"
#include <QMessageBox>

mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    this -> populateListView();

    QObject::connect(this->ui->visualiseButton, &QPushButton::clicked, this, &mainWindow::populateListView);
    QObject::connect(this->ui->showUnpaidBillsButton, &QPushButton::clicked, this, &mainWindow::showUnpaidBills);
    QObject::connect(this -> ui->calculateUnpaidBillsButton, &QPushButton::clicked, this, &mainWindow::calculateTotalOfUnpaidBills);
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::populateListView() {
    ui->listWidget->setStyleSheet(" background-color: black;");
    this -> ui->listWidget->clear();
    vector<Bill> billList = service.getBills();

    for(auto bill : billList){
        QString companyName = QString::fromStdString(bill.getCompanyName());
        QString sum = QString::fromStdString(to_string(bill.getSum()));
        QString label = QString("Company name: " + companyName + " | sum: " + sum);
        this -> ui->listWidget->addItem(label);
    }
}

void mainWindow::showUnpaidBills() {
    ui->listWidget->setStyleSheet(" background-color: red;");
    this -> ui->listWidget->clear();
    vector<Bill> billList = service.getUnpaidBills(ui->checkBox->isChecked());

    for(auto bill : billList){
        QString companyName = QString::fromStdString(bill.getCompanyName());
        QString sum = QString::fromStdString(to_string(bill.getSum()));
        QString label = QString("Company name: " + companyName + " | sum: " + sum);
        this -> ui->listWidget->addItem(label);
    }
}

void mainWindow::calculateTotalOfUnpaidBills() {
    QString text = ui->lineEdit->text();
    ui->lineEdit->clear();

    string name = text.toStdString();
    bool isPayed = ui->checkBox->isChecked();
    qDebug() << "IsPayed: " << isPayed;
    float sum = service.totalOfUnpaidBills(name);

    if(sum == -1) {
        QMessageBox::critical(this, "Error", "Company not found");
        return;
    }

    ui->label->setText("Total of unpaid bills: " + QString::fromStdString(to_string(sum)));
}
