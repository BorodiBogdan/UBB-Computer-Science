//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_CONNECTER_H
#define INC_1ST_QT_PROJECT_CONNECTER_H
#include "mainwindow.h"
#include "databasewidget.h"
#include "adminwidget.h"

class Connecter {
public:
    Connecter(mainWindow *w);
    Connecter();
    void connectAll();
private:
    void connectDataBaseWidgetToMainWindow();
    void connectChooseFileTypeToMainWindow();
    void connectChooseConnectionTypeWidgetToMainWindow();
    void connectAdminWidgetToMainWindow();
    void connectUserWidgetToMainWindow();
    void connectWatchListWidgetToMainWindow();
    void connectUserWidgetToWatchListWidget();
    void connectAdminWidgetToWatchListWidget();
    void connectChartWidgetToMainWindow();
    mainWindow *myMainWindow;
};


#endif //INC_1ST_QT_PROJECT_CONNECTER_H
