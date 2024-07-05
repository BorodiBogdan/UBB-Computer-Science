//
// Created by Bob on 6/27/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <QGraphicsScene>
#include <QColor>
#include <QFont>
#include <QGraphicsItem>
#include <QPen>


gui::gui(QWidget *parent) :
        QWidget(parent), ui(new Ui::gui) {
    ui->setupUi(this);

    QGraphicsScene *myScene = new QGraphicsScene;
    ui->graphicsView->setScene(myScene);

    //add a rectangle
    myScene->addRect(0, 0, 20, 20, QPen(Qt::black), QBrush(Qt::red));
    //add text to coordinates 0,0
    myScene->addText("Hello, world!", QFont("Arial", 10));
    //add text to coordinates 20, 20
    myScene->addText("Hello, world!", QFont("Arial", 10))->setPos(20, 20);

}

gui::~gui() {
    delete ui;
}
