//
// Created by Bob on 5/28/2024.
//

#ifndef OOPTEST_MAINWINDOW_H
#define OOPTEST_MAINWINDOW_H

#include <QMainWindow>
#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;
public slots:
    void populateList();
    void updateSimilarity();
private:
    Ui::MainWindow *ui;
    Service service;
};


#endif //OOPTEST_MAINWINDOW_H