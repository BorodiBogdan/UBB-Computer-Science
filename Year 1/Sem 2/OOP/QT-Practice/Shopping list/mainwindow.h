//
// Created by Bob on 5/26/2024.
//

#ifndef INC_1ST_QT_PROJECT_MAINWINDOW_H
#define INC_1ST_QT_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include "service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void populateListWidget();
    void populateSecondWidget();
private:
    Ui::MainWindow *ui;
    Service service;
};


#endif //INC_1ST_QT_PROJECT_MAINWINDOW_H
