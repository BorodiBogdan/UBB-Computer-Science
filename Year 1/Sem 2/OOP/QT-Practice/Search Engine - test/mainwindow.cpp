//
// Created by Bob on 5/27/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"


mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);

    this -> loadDocuments();

    QObject::connect(this -> ui->matchLineEdit, &QLineEdit::textChanged, this, &mainWindow::loadDocuments);
    QObject::connect(this -> ui->showBestMatchButton, &QPushButton::clicked, this, &mainWindow::ShowBestMatching);
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::ShowBestMatching() {
    this -> ui->documentListWidget->clear();

    string text = this -> ui->matchLineEdit->text().toStdString();
    Document document = this -> service.getBestMatch(text);

    string labelText = document.getName() + " | " + document.getKeyWords();
    QString label = QString::fromStdString(labelText);

    this -> ui->documentListWidget->addItem(label);
}

void mainWindow::loadDocuments() {
    this -> ui->documentListWidget->clear();

    string text = this -> ui->matchLineEdit->text().toStdString();

    vector<Document> documentList;

    if(text == "")
        documentList = this -> service.getDocuments();
    else
        documentList = this -> service.getMatchingStrings(text);

    for(auto document : documentList){
        string labelText = document.getName() + " | " + document.getKeyWords();
        QString label = QString::fromStdString(labelText);

        this -> ui->documentListWidget->addItem(label);
    }
}
