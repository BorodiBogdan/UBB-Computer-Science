//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_MAINWINDOW_H
#define INC_1ST_QT_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include "databasewidget.h"
#include "choosemodewidget.h"
#include "chooseconnectionmodewidget.h"
#include "adminwidget.h"
#include "userwidget.h"
#include "includes/service/service.h"
#include "watchlistwidget.h"
#include "barchartwidget.h"
#include "tableView.h"

namespace WidgetConstants{
    const int CHOOSEDATABASE = 0;
    const int CHOOSEFILETYPE = 1;
    const int CHOOSECONNECTIONMODE = 2;
    const int ADMINMODE = 3;
    const int USERMODE = 4;
    const int WATCHLIST = 5;
    const int GENRECHART = 6;
}

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent, Service& service);

    ~mainWindow() override;
public slots:
    void PerformingRealDataBase();
    void PerformingTextDataBase();
    void PerformFileTypeChooseBackButton();
    void PerformChooseConnectionModeBackButton();
    void PerformCSVFilePath();
    void PerformHTMLFilePath();
    void PerformTXTFilePath();
    void PerformUserMode();
    void PerformAdminMode();
    void PerformAdminModeBackButton();
    void PerformUserModeBackButton();
    void PerformWatchListBackButton();
    void PerformOpenWatchList();
    void PerformOpenGenreChart();
    void PerformBackButtonFromGenreChart();
private:
    Service &service;

    Ui::mainWindow *ui;
    QStackedLayout *myStackedLayout;
    DataBaseWidget *ChooseBetweenDatabases;
    ChooseFileTypeWidget *chooseFileTypeForWatchList;
    chooseConnectionModeWidget *chooseConnectionTypeWidget;
    AdminWidget *adminWidget;
    userWidget *UserWidget;
    watchListWidget *WatchListWidget;
    barChartWidget *myAppBarChartWidget;

    friend class Connecter;
};


#endif //INC_1ST_QT_PROJECT_MAINWINDOW_H
