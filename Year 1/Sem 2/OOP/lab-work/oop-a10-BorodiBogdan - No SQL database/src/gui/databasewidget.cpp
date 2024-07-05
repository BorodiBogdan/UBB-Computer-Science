//
// Created by Bob on 5/9/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DataBaseWidget.h" resolved

#include "databasewidget.h"
#include <Qrect>


DataBaseWidget::DataBaseWidget(QWidget *parent) {
    this -> FileButton = new QPushButton("Text File");
    this -> DataBaseButton = new QPushButton("Data Base");
    this->ExitButton = new QPushButton("Exit");

    auto *BoxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    BoxLayout->setAlignment(Qt::AlignCenter);
    BoxLayout->addWidget(FileButton);
    BoxLayout->addWidget(DataBaseButton);
    BoxLayout->addWidget(ExitButton);

    this->setLayout(BoxLayout);

    connect(FileButton, &QPushButton::clicked,[&](){
       emit  this -> fileDataBaseButtonClicked();
    });

    connect(DataBaseButton, &QPushButton::clicked,[&](){
        emit  this -> realDataBaseButtonClicked();
    });

    connect(ExitButton, &QPushButton::clicked,[&](){
        emit  this -> exitButtonClicked();
    });
}

DataBaseWidget::~DataBaseWidget() {
    delete this ->DataBaseButton;
    delete this ->FileButton;
}
