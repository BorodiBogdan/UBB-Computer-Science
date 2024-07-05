
#include "departmentwidget.h"
#include "ui_DepartMentWidget.h"



DepartMentWidget::DepartMentWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::DepartMentWidget) {
    ui->setupUi(this);


}

DepartMentWidget::~DepartMentWidget() {
    delete ui;
}

DepartMentWidget::DepartMentWidget(department givenDepartment, vector<volunteer> volunteerInfo) :
    ui(new Ui::DepartMentWidget) {
    ui->setupUi(this);

    //ui->departmentName->setText(QString::fromStdString(givenDepartment.getName()));
    ui->departmentDescription->setPlaceholderText(QString::fromStdString(givenDepartment.getDescription()));

    for(auto v : volunteerInfo){
        ui->volunteerList->addItem(QString::fromStdString(v.getName()));
    }
}
