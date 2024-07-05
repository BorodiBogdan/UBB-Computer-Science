//
// Created by Bob on 5/9/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_chooseConnectionModeWidget.h" resolved

#include "chooseconnectionmodewidget.h"


chooseConnectionModeWidget::chooseConnectionModeWidget(QWidget *parent) {
    adminButton = new QPushButton("Admin mode");
    userButton = new QPushButton("User mode");
    backButton = new QPushButton("Back");

    auto *myLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    myLayout->addWidget(adminButton);
    myLayout->addWidget(userButton);
    myLayout->addWidget(genreChartButton);
    myLayout->addWidget(backButton);
    setLayout(myLayout);

    connect(backButton, &QPushButton::clicked,[&](){
        emit  this -> backButtonClickedSignal();
    });

    connect(userButton, &QPushButton::clicked,[&](){
        emit  this -> userModeSelectedSignal();
    });

    connect(adminButton, &QPushButton::clicked,[&](){
        emit  this -> adminModeSelectedSignal();
    });
}

chooseConnectionModeWidget::~chooseConnectionModeWidget() {
}