//
// Created by Bob on 5/26/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this -> populateListWidget();
    QObject::connect(this -> ui->categoryOrNameLineEdit, &QLineEdit::textChanged, this, &MainWindow::populateListWidget);
    QObject::connect(this -> ui->categoryShowItemsButton, &QPushButton::clicked, this, &MainWindow::populateSecondWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateListWidget() {
    string name =  this ->ui->categoryOrNameLineEdit->text().toStdString();

    vector<Item> itemList;

    if(name == "")
        itemList = this -> service.getItems();
    else
        itemList = this -> service.getItemMatching(name);


    this -> ui->listWidget->clear();

    for(auto item: itemList){
        string labelText = item.getCategory() + " | " + item.getName() + " | " + to_string(item.getQuantity());
        QString label = QString::fromStdString(labelText);
        this -> ui->listWidget->addItem(label);
    }
}

void MainWindow::populateSecondWidget() {
    string category = this->ui->CategorySearchLineEdit->text().toStdString();
    this -> ui->listWidgetForCategorySearch->clear();

    for(auto item: this -> service.getItemsByCategory(category)){
        string labelText = item.getCategory() + " | " + item.getName() + " | " + to_string(item.getQuantity());
        QString label = QString::fromStdString(labelText);
        this -> ui->listWidgetForCategorySearch->addItem(label);
    }
}
