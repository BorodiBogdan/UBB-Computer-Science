//
// Created by Bob on 5/9/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "../../ui_mainwindow.h"
using namespace WidgetConstants;

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::PerformingRealDataBase(){
    try {
        service.setTypeOfDataBase(1);
        this->adminWidget->modifyTableInformationBasedOnDataBase();

        qDebug() << "Data Base clicked!";
        this->myStackedLayout->setCurrentIndex(CHOOSEFILETYPE);
    }
    catch (RepositoryException &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
void mainWindow::PerformingTextDataBase(){
    service.setTypeOfDataBase(0);
    this->adminWidget->modifyTableInformationBasedOnDataBase();

    qDebug() << "Text File clicked!";
    this -> myStackedLayout->setCurrentIndex(CHOOSEFILETYPE);
}
mainWindow::mainWindow(QWidget *parent, Service &service) :
        QMainWindow(parent), ui(new Ui::mainWindow), service(service) {

    ui->setupUi(this);

    this -> ChooseBetweenDatabases = new DataBaseWidget;
    this -> chooseFileTypeForWatchList = new ChooseFileTypeWidget;
    this -> chooseConnectionTypeWidget = new chooseConnectionModeWidget;
    this -> adminWidget = new AdminWidget(this, this->service);
    this -> UserWidget = new userWidget(nullptr, service);
    this -> WatchListWidget = new watchListWidget;
    this -> myAppBarChartWidget = new barChartWidget(nullptr, this -> service);


    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setWindowTitle("Movie menagement app");

    resize(600, 400);

    myStackedLayout = new QStackedLayout(centralWidget);

    myStackedLayout->addWidget(this -> ChooseBetweenDatabases);
    myStackedLayout->addWidget(this -> chooseFileTypeForWatchList);
    myStackedLayout->addWidget(this -> chooseConnectionTypeWidget);
    myStackedLayout->addWidget(this -> adminWidget);
    myStackedLayout->addWidget(this -> UserWidget);;
    myStackedLayout->addWidget(this -> WatchListWidget);
    myStackedLayout->addWidget(this -> myAppBarChartWidget);
}

void mainWindow::PerformFileTypeChooseBackButton() {
    myStackedLayout->setCurrentIndex(CHOOSEDATABASE);
}

void mainWindow::PerformChooseConnectionModeBackButton() {
    myStackedLayout->setCurrentIndex(CHOOSEFILETYPE);
}

void mainWindow::PerformCSVFilePath() {
    service.setTypeOfRepo("CSV");
    qDebug() << "CSV clicked!";
    myStackedLayout->setCurrentIndex(CHOOSECONNECTIONMODE);
}

void mainWindow::PerformTXTFilePath() {
    service.setTypeOfRepo("TXT");
    qDebug() << "TXT clicked!";
    myStackedLayout->setCurrentIndex(CHOOSECONNECTIONMODE);
}

void mainWindow::PerformHTMLFilePath() {
    service.setTypeOfRepo("HTML");
    qDebug() << "html clicked!";
    myStackedLayout->setCurrentIndex(CHOOSECONNECTIONMODE);
}

void mainWindow::PerformUserMode() {
    qDebug() << "User mode clicked!";
    this -> myStackedLayout->setCurrentIndex(USERMODE);
}

void mainWindow::PerformAdminMode() {
    qDebug() << "Admin mode clicked!";
    this -> myStackedLayout->setCurrentIndex(ADMINMODE);
}

void mainWindow::PerformAdminModeBackButton() {
    qDebug() << "Back button clicked!";
    this -> myStackedLayout->setCurrentIndex(CHOOSECONNECTIONMODE);
}

void mainWindow::PerformUserModeBackButton() {
    qDebug() << "Back button clicked!";
    this -> myStackedLayout->setCurrentIndex(CHOOSECONNECTIONMODE);
}

void mainWindow::PerformWatchListBackButton() {
    qDebug() << "Back button clicked!";
    this -> myStackedLayout->setCurrentIndex(USERMODE);
}

void mainWindow::PerformOpenWatchList() {
    qDebug() << "WatchList clicked!";
    this -> myStackedLayout->setCurrentIndex(WATCHLIST);
}

void mainWindow::PerformOpenGenreChart() {
    this -> myStackedLayout->setCurrentIndex(GENRECHART);
}

void mainWindow::PerformBackButtonFromGenreChart() {
    this -> myStackedLayout->setCurrentIndex(ADMINMODE);
}
