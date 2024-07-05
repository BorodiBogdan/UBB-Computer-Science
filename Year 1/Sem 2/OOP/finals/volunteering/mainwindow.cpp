#include "mainwindow.h"
#include "ui_mainWIndow.h"


mainWIndow::mainWIndow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWIndow) {
    ui->setupUi(this);

    for(auto d : this -> controller.getDepartments()){
        DepartMentWidget *department = new DepartMentWidget(d, this -> controller.getVolunteers());
        department->show();
    }
}

mainWIndow::~mainWIndow() {
    delete ui;
}
