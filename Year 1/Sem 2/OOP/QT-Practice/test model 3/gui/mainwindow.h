//
// Created by Bob on 5/22/2024.
//

#ifndef OOPTEST_MAINWINDOW_H
#define OOPTEST_MAINWINDOW_H

#include <QMainWindow>
#include "service/Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;
public slots:
    void showUnpaidBills();
    void populateListView();
    void calculateTotalOfUnpaidBills();
private:
    Ui::mainWindow *ui;
    Service service;
};


#endif //OOPTEST_MAINWINDOW_H
