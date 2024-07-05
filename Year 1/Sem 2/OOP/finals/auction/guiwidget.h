//
// Created by Bob on 6/24/2024.
//

#ifndef INC_1ST_QT_PROJECT_GUIWIDGET_H
#define INC_1ST_QT_PROJECT_GUIWIDGET_H

#include <QWidget>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guiWidget; }
QT_END_NAMESPACE

class guiWidget : public QWidget, public Observer{
Q_OBJECT

public:
    guiWidget(controller& service, User user);

    ~guiWidget() override;
    void update() override;
public slots:
    void comboBoxSelectionChanged();
    void addButtonClicked();
    void showOffers();
    void bidUser();
private:
    Ui::guiWidget *ui;
    controller& service;
    User user;
    bool adminCredidential;
};


#endif //INC_1ST_QT_PROJECT_GUIWIDGET_H
