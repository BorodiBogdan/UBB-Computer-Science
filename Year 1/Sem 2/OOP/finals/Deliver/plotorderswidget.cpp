//
// Created by Bob on 6/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_plotOrdersWidget.h" resolved

#include "plotorderswidget.h"
#include "ui_plotOrdersWidget.h"
#include <QGraphicsScene>
#include <QColor>

plotOrdersWidget::plotOrdersWidget(Service &service, QWidget *parent) :
        QWidget(parent), ui(new Ui::plotOrdersWidget), service{service} {
    ui->setupUi(this);
    this->setWindowTitle("Plot Orders");

    updateImage();

}
plotOrdersWidget::~plotOrdersWidget() {
    delete ui;
}

void plotOrdersWidget::update() {
    updateImage();
}

void plotOrdersWidget::updateImage() {
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //we want to plot the coordinates of the packages from service
    for(auto &package: service.get_packages()){
        if(package.getDeliveryStatus() == "false")
        scene->addEllipse(package.getLocation().x, package.getLocation().y, 5, 5, QPen(Qt::black), QBrush(Qt::red));

    }
}
