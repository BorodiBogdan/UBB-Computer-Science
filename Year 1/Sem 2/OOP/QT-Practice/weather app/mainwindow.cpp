//
// Created by Bob on 5/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>
#include <QBoxLayout>
#include <string>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this -> populateListView();

    QObject::connect(this->ui->filterButton, &QPushButton::clicked, this , &MainWindow::populateListView);
    QObject::connect(this -> ui->displayIntervalsButton, &QPushButton::clicked, this, &MainWindow::displayIntervalsAndHours);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateListView() {
    this -> ui->weatherListWidget->clear();
    string text = this -> ui->filterLineEdit->text().toStdString();
    ui->filterLineEdit->clear();
    vector<Weather> wList;

    if(text == "")
       wList = this -> service.getWeatherListSorted();
    else
        wList = this -> service.getWeatherListFiltered(stoi(text));

    for(auto w : wList){
        string labelText = to_string(w.getStart()) + " | " + to_string(w.getEnd()) + " | " + to_string(w.getTemperature()) + " | " + w.getDescription();
        QString label = QString::fromStdString(labelText);

        this -> ui->weatherListWidget->addItem(label);
    }

    QBrush w = QBrush("Red");
    this -> ui->weatherListWidget->item(2)->setForeground(w);
}

void MainWindow::displayIntervalsAndHours() {

    QWidget *widget = new QWidget;
    QVBoxLayout *lay = new QVBoxLayout;

    QListWidget *list = new QListWidget;
    QLabel *label = new QLabel;

    string s = this -> ui->startLineEdit->text().toStdString();

    int start;
    if(s != "")
        start = stoi(s);

    string description = this -> ui->descripionLineEdit->text().toStdString();


    label->setText(QString::fromStdString(to_string(service.getTotalOfHours(start, description))));

    if(service.getWeatherAfterAnInterval(start, description).size() == 0){
        QMessageBox *mBox = new QMessageBox;
        mBox->setText("Error, nothing found!");
        mBox->show();
    }else {

        for (auto w: this->service.getWeatherAfterAnInterval(start, description)) {
            string labelText = to_string(max(w.getStart(), start)) + " | " + to_string(w.getEnd()) + " | " +
                               to_string(w.getTemperature()) + " | " + w.getDescription();
            QString label = QString::fromStdString(labelText);

            list->addItem(label);
        }

        lay->addWidget(list);
        lay->addWidget(label);

        widget->setLayout(lay);

        widget->show();
    }
}
