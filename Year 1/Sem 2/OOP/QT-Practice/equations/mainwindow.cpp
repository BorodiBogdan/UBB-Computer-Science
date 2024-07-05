//
// Created by Bob on 5/27/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"
#include <cmath>

mainWindow::mainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);

    this -> populateList();

    QObject::connect(this->ui->computeButton, &QPushButton::clicked, this, &mainWindow::showSolution);
    QObject::connect(this->ui->updateButton, &QPushButton::clicked, this, &mainWindow::updateCoeff);
}

mainWindow::~mainWindow() {
    delete ui;
}

void mainWindow::populateList() {
    this -> ui->equationListWidget->clear();
    vector<equation> eqList = this -> service.getEquations();
    int rowNumber = 0;

    for(auto e : eqList){
        string eq = to_string(e.getX2()) + "x^2 ";

        if(e.getX() < 0)
            eq += "- ";
        else
            eq += "+ ";

        eq += to_string(e.getX()) + "x ";

        if(e.getC() < 0)
            eq += "- ";
        else
            eq += "+ ";

        eq += to_string(e.getC());

        QString label = QString::fromStdString(eq);


        this -> ui->equationListWidget->addItem(label);

        QListWidgetItem *it = this ->ui->equationListWidget->item(rowNumber);
        QFont d;
        d.setBold(1);

        if(e.isReal())
            it->setFont(d);

        rowNumber++;
    }
}

void mainWindow::showSolution() {
    QList <QListWidgetItem *> selectedItems = this -> ui->equationListWidget->selectedItems();

    QListWidgetItem* selectedItem = selectedItems.first();

    int index = this -> ui->equationListWidget->row(selectedItem);

    equation eq = this -> service.getEquations()[index];

    float delta = eq.getX() * eq.getX() - 4 * eq.getC() * eq.getX2();

    string r = "";

    if(eq.isReal()) {
        float result1 = (-sqrt(delta) - eq.getX()) / eq.getX2();
        float result2 = (sqrt(delta) - eq.getX()) / eq.getX2();

        string res1 = to_string(result1);
        string res = to_string(result2);

        r = "x1: " + to_string(result1) + " x2: " + to_string(result2);
    }
    else{
        r = "x1: i" + to_string(sqrt(-delta)/(eq.getX2() * 2)) + " +" + to_string(eq.getX()/(eq.getX2() * 2));
        r += " x2: -i" + to_string(sqrt(-delta)/(eq.getX2() * 2)) + " +" + to_string(eq.getX()/(eq.getX2() * 2));
    }
    this -> ui->solutionLabel->setText(QString::fromStdString(r));
}

void mainWindow::updateCoeff() {
    QList <QListWidgetItem *> selectedItems = this -> ui->equationListWidget->selectedItems();

    QListWidgetItem* selectedItem = selectedItems.first();

    int index = this -> ui->equationListWidget->row(selectedItem);

    string text = this -> ui->lineEdit->text().toStdString();


    string token = "";
    string tokens[3];
    int k = 0;
    equation e;

    for(auto e : text){
        if(e == ','){
            trimWhiteSpaces(token);
            tokens[k++] = token;
            qDebug() << token <<"\n";
            token = "";
        }
        else
            token += e;

    }
    trimWhiteSpaces(token);
    tokens[2] = token;
    qDebug() << token <<"\n";

    e.setX2(stoi(tokens[0]));
    e.setX(stoi(tokens[1]));
    e.setC(stoi(tokens[2]));

    this -> service.updateEq(index, e);
    this -> populateList();
    this -> ui->lineEdit->clear();
}
