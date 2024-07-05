//
// Created by Bob on 5/9/2024.
//

#include "Connecter.h"
#include <QObject>

void Connecter::connectDataBaseWidgetToMainWindow(){
    QObject::connect(myMainWindow->ChooseBetweenDatabases, &DataBaseWidget::fileDataBaseButtonClicked, myMainWindow, &mainWindow::PerformingTextDataBase);
    QObject::connect( myMainWindow->ChooseBetweenDatabases, &DataBaseWidget::realDataBaseButtonClicked,  myMainWindow, &mainWindow::PerformingRealDataBase);
    QObject::connect( myMainWindow->ChooseBetweenDatabases, &DataBaseWidget::exitButtonClicked,  myMainWindow, &mainWindow::close);
}

void Connecter::connectChooseFileTypeToMainWindow() {

    auto *chooseFileType = myMainWindow->chooseFileTypeForWatchList;

    QObject::connect(chooseFileType, &ChooseFileTypeWidget::backButtonClickedSignal, myMainWindow, &mainWindow::PerformFileTypeChooseBackButton);
    QObject::connect(chooseFileType, &ChooseFileTypeWidget::CSVFilePathSignal, myMainWindow, &mainWindow::PerformCSVFilePath);
    QObject::connect(chooseFileType, &ChooseFileTypeWidget::HTMLFilePathSignal, myMainWindow, &mainWindow::PerformHTMLFilePath);
    QObject::connect(chooseFileType, &ChooseFileTypeWidget::TXTFilePathSignal, myMainWindow, &mainWindow::PerformTXTFilePath);
}

void Connecter::connectChooseConnectionTypeWidgetToMainWindow() {
    QObject::connect(myMainWindow->chooseConnectionTypeWidget, &chooseConnectionModeWidget::backButtonClickedSignal, myMainWindow, &mainWindow::PerformChooseConnectionModeBackButton);
    QObject::connect(myMainWindow->chooseConnectionTypeWidget, &chooseConnectionModeWidget::userModeSelectedSignal, myMainWindow, &mainWindow::PerformUserMode);
    QObject::connect(myMainWindow->chooseConnectionTypeWidget, &chooseConnectionModeWidget::adminModeSelectedSignal, myMainWindow, &mainWindow::PerformAdminMode);
}
void Connecter::connectAdminWidgetToMainWindow() {
    QObject::connect(myMainWindow->adminWidget, &AdminWidget::adminBackButtonSignal, myMainWindow, &mainWindow::PerformAdminModeBackButton);
}
void Connecter::connectAll(){
    this->connectDataBaseWidgetToMainWindow();
    this->connectChooseFileTypeToMainWindow();
    this->connectChooseConnectionTypeWidgetToMainWindow();
    this->connectAdminWidgetToMainWindow();
    this->connectUserWidgetToMainWindow();
    this->connectWatchListWidgetToMainWindow();
    this->connectUserWidgetToWatchListWidget();
    this->connectAdminWidgetToWatchListWidget();
    this->connectChartWidgetToMainWindow();
}
Connecter::Connecter(mainWindow *w) {
    this->myMainWindow = w;
}

Connecter::Connecter() {

}

void Connecter::connectUserWidgetToMainWindow() {
    QObject::connect(myMainWindow->UserWidget, &userWidget::userBackButtonSignal, myMainWindow, &mainWindow::PerformUserModeBackButton);
    QObject::connect(myMainWindow->UserWidget, &userWidget::openWatchlistSignal, myMainWindow, &mainWindow::PerformOpenWatchList);
}

void Connecter::connectWatchListWidgetToMainWindow() {
    QObject::connect(myMainWindow->WatchListWidget, &watchListWidget::watchListBackButtonSignal, myMainWindow, &mainWindow::PerformWatchListBackButton);
}

void Connecter::connectUserWidgetToWatchListWidget() {
    QObject::connect(myMainWindow->UserWidget, &userWidget::openWatchlistSignal, myMainWindow, &mainWindow::PerformOpenWatchList);
    QObject::connect(myMainWindow->UserWidget, &userWidget::changeWatchList, myMainWindow->WatchListWidget, &watchListWidget::updateTableInformationBasedOnDataBase);
}

void Connecter::connectAdminWidgetToWatchListWidget() {
    QObject::connect(myMainWindow->adminWidget, &AdminWidget::changeWatchList, myMainWindow->WatchListWidget, &watchListWidget::updateTableInformationBasedOnDataBase);
}

void Connecter::connectChartWidgetToMainWindow() {
    QObject::connect(myMainWindow->myAppBarChartWidget, &barChartWidget::chartBackButton, myMainWindow, &mainWindow::PerformBackButtonFromGenreChart);
    QObject::connect(myMainWindow->adminWidget, &AdminWidget::updateGenreChartSignal, myMainWindow->myAppBarChartWidget, &barChartWidget::updateChart);
    QObject::connect(myMainWindow->adminWidget, &AdminWidget::updateGenreChartSignal, myMainWindow, &mainWindow::PerformOpenGenreChart);
}
