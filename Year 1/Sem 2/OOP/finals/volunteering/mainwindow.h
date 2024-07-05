//
// Created by Bob on 6/23/2024.
//

#ifndef VOLUNTEERING_MAINWINDOW_H
#define VOLUNTEERING_MAINWINDOW_H

#include <QMainWindow>
#include "departmentwidget.h"
#include "service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainWIndow; }
QT_END_NAMESPACE

class mainWIndow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainWIndow(QWidget *parent = nullptr);

    ~mainWIndow() override;

private:
    Ui::mainWIndow *ui;
    service controller;
};


#endif //VOLUNTEERING_MAINWINDOW_H
