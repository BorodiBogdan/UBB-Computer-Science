//
// Created by Bob on 5/28/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this -> populateList();

    QObject::connect(this -> ui->searchListWiget, &QListWidget::itemSelectionChanged , this, &MainWindow::updateSimilarity);
    QObject::connect(this -> ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::populateList);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateList() {
    this -> ui->searchListWiget->clear();

    vector <Item> itemList;
    string textFromLineEdit = this -> ui->searchLineEdit->text().toStdString();

    string lineEditText = this -> ui->searchLineEdit->text().toStdString();

    if(lineEditText == "")
        itemList = this -> service.getItemsSortedByLength();
    else itemList = this -> service.getItemsByString(lineEditText);
    int row = 0;
    for(auto item : itemList){
        string text = item.getName() + " | " + item.getKeyWords();
        QString textLabel = QString::fromStdString(text);

        this -> ui->searchListWiget->addItem(textLabel);

        QListWidgetItem *it = this -> ui->searchListWiget->item(row);
        row++;
    }
}

void MainWindow::updateSimilarity() {
    string textFromLineEdit = this -> ui->searchLineEdit->text().toStdString();

    if(textFromLineEdit == "") {
        this -> ui->labelForSimilarity->setText("Similarity: ");
        return;
    }

    QList <QListWidgetItem *> items = this -> ui->searchListWiget->selectedItems();

    if(items.size() == 0)
        return;

    QListWidgetItem *it = items.first();
    string textFromSelectedItem = it->text().toStdString();

    float similarity = service.computeSImilarity(textFromLineEdit, textFromSelectedItem);

    string t = to_string(similarity);

    this -> ui->labelForSimilarity->setText(QString::fromStdString("Similarity: " + t));

}
