//
// Created by Bob on 5/17/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_watchListWidget.h" resolved

#include "watchlistwidget.h"
#include <QVBoxLayout>
#include <QPushButton>


watchListWidget::watchListWidget(QWidget *parent){
    this -> tableWidget = new MyModel;

    QPushButton *backButton = new QPushButton("BACK");

    QObject::connect(backButton, &QPushButton::clicked, this, [&]{
        emit this -> watchListBackButtonSignal();
    });

    QVBoxLayout *layout = new QVBoxLayout;

    QTableView *myView = new QTableView;
    myView->setModel(tableWidget);

    layout->addWidget(myView);
    layout->addWidget(backButton);

    this ->setLayout(layout);
}


watchListWidget::~watchListWidget() {
}

void watchListWidget::updateTableInformationBasedOnDataBase(vector<Movie> movies) {
    this ->tableWidget->setMovies(movies);
}
