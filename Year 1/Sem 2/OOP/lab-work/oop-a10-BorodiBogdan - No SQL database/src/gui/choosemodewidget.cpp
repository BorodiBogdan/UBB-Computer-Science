//
// Created by Bob on 5/9/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChooseModeWidget.h" resolved

#include "choosemodewidget.h"

ChooseFileTypeWidget::ChooseFileTypeWidget(QWidget *parent){
    this -> TXT = new QPushButton("TEXT");
    this -> CSV = new QPushButton("CSV");
    this -> HTML = new QPushButton("HTML");
    this -> backButton = new QPushButton("BACK");

    auto *chooseUserLayout = new QVBoxLayout();
    chooseUserLayout->addWidget(TXT);
    chooseUserLayout->addWidget(CSV);
    chooseUserLayout->addWidget(HTML);
    chooseUserLayout->addWidget(backButton);

    chooseUserLayout->setAlignment(Qt::AlignCenter);

    setLayout(chooseUserLayout);

    connect(backButton, &QPushButton::clicked,[&](){
        emit  this -> backButtonClickedSignal();
    });

    connect(HTML, &QPushButton::clicked,[&](){
        emit  this -> HTMLFilePathSignal();
    });

    connect(CSV, &QPushButton::clicked,[&](){
        emit  this -> CSVFilePathSignal();
    });

    connect(TXT, &QPushButton::clicked,[&](){
        emit  this -> TXTFilePathSignal();
    });
}

ChooseFileTypeWidget::~ChooseFileTypeWidget() {
    delete CSV;
    delete HTML;
    delete TXT;
}
