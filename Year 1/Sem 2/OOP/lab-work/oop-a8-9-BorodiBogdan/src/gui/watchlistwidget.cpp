//
// Created by Bob on 5/17/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_watchListWidget.h" resolved

#include "watchlistwidget.h"
#include <QVBoxLayout>
#include <QPushButton>


watchListWidget::watchListWidget(QWidget *parent) :
        QWidget(parent){
    this->tableWidget = createTableWidgetForWatchList();

    QPushButton *backButton = new QPushButton("BACK");

    QObject::connect(backButton, &QPushButton::clicked, [&](){
        emit watchListBackButtonSignal();
    });

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(this->tableWidget);
    layout->addWidget(backButton);

    setLayout(layout);

}

watchListWidget::~watchListWidget() {
}

QTableWidget *watchListWidget::createTableWidgetForWatchList() {
    QTableWidget *tableWidget = new QTableWidget(0, 5);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Title" << "Genre" << "Year" << "Likes" << "Trailer");

    return tableWidget;
}

void watchListWidget::updateTableInformationBasedOnDataBase(vector<Movie> movies) {
    this->tableWidget->setRowCount(0);

    for (const auto &movie : movies) {
        this -> tableWidget -> insertRow(this -> tableWidget -> rowCount());
        this -> tableWidget -> setItem(this -> tableWidget -> rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
        this -> tableWidget -> setItem(this -> tableWidget -> rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        this -> tableWidget -> setItem(this -> tableWidget -> rowCount() - 1, 2, new QTableWidgetItem(QString::number(movie.getYearOfRelease())));
        this -> tableWidget -> setItem(this -> tableWidget -> rowCount() - 1, 3, new QTableWidgetItem(QString::number(movie.getNumberOfLikes())));
        this -> tableWidget -> setItem(this -> tableWidget -> rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
    }
}
