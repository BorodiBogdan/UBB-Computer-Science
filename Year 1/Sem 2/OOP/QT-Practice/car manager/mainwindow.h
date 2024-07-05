//
// Created by Bob on 5/28/2024.
//

#ifndef CARMANAGEMENT_MAINWINDOW_H
#define CARMANAGEMENT_MAINWINDOW_H

#include <QMainWindow>
#include "service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;
public slots:
    void populateListView();
    void getCarsByManufacturer();
private:
    Ui::mainWindow *ui;
    Service service;
};


#endif //CARMANAGEMENT_MAINWINDOW_H
