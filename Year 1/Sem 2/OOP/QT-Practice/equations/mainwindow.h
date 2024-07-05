//
// Created by Bob on 5/27/2024.
//

#ifndef EQUATIONS_MAINWINDOW_H
#define EQUATIONS_MAINWINDOW_H

#include <QWidget>
#include "service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QWidget {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;

public slots:
    void populateList();
    void showSolution();
    void updateCoeff();
private:
    Ui::mainWindow *ui;
    Service service;
};


#endif //EQUATIONS_MAINWINDOW_H
