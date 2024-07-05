//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_PLOTORDERSWIDGET_H
#define INC_1ST_QT_PROJECT_PLOTORDERSWIDGET_H

#include <QWidget>
#include "Service.h"
#include "Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class plotOrdersWidget; }
QT_END_NAMESPACE

class plotOrdersWidget : public QWidget, public Observer {
Q_OBJECT

public:
    plotOrdersWidget(Service &service, QWidget *parent = nullptr);

    ~plotOrdersWidget() override;
    void update() override;
public slots:
    void updateImage();
private:
    Service &service;
    Ui::plotOrdersWidget *ui;
};


#endif //INC_1ST_QT_PROJECT_PLOTORDERSWIDGET_H
