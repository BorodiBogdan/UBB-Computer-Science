#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include "Service.h"

class ViewBacteriaWindow : public QWidget {
Q_OBJECT
public:
    explicit ViewBacteriaWindow(Service& service, QWidget* parent = nullptr);

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    Service& service;
    void setup();
    void displayBacteria();
};
