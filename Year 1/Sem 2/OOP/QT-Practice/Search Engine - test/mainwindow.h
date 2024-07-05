//
// Created by Bob on 5/27/2024.
//

#ifndef SEARCH_ENGINE___TEST_MAINWINDOW_H
#define SEARCH_ENGINE___TEST_MAINWINDOW_H

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
    void loadDocuments();
    void ShowBestMatching();

private:
    Service service;
    Ui::mainWindow *ui;
};


#endif //SEARCH_ENGINE___TEST_MAINWINDOW_H
