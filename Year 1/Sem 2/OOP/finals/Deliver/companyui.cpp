// You may need to build the project (run Qt uic code generator) to get "ui_companyUi.h" resolved

#include "companyui.h"
#include "ui_companyUi.h"
#include <QColor>
#include "utils.h"
#include "plotorderswidget.h"


companyUi::companyUi(Service &service, QWidget *parent) :
        QWidget(parent), ui(new Ui::companyUi), service{service} {
    ui->setupUi(this);

    this ->setWindowTitle("courier company");

    populate_list();
    QObject::connect(ui->packagesButton, &QPushButton::clicked, this, [&]{
        plotOrdersWidget *plotOrdersWidget = new class plotOrdersWidget(service);
        plotOrdersWidget->show();
        service.addObserver(plotOrdersWidget);
    });
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &companyUi::add_package);
}
companyUi::~companyUi() {
    delete ui;
}

void companyUi::populate_list() {
    this->ui->packageListWidget->clear();

    for(auto &package: service.get_packages()){
        ui->packageListWidget->addItem(QString::fromStdString(package.toString()));

        if(package.getDeliveryStatus() == "true"){
            ui->packageListWidget->item(ui->packageListWidget->count() - 1)->setBackground(Qt::green);
        }

    }
}

void companyUi::add_package() {
    string recipient = ui->recipientLineEdit->text().toStdString();
    vector<string> addressTokens = utils::tokenize(ui->adressLineEdit->text().toStdString(), ",");

    if(addressTokens.size() != 2)
        return;

    string street = addressTokens[0];
    string number = addressTokens[1];
    vector <string> location = utils::tokenize(ui->locationLineEdit->text().toStdString(), ",");

    if(location.size() != 2)
        return;


    int x = stoi(location[0]);
    int y = stoi(location[1]);
    Location l{x, y};

    this -> service.addPackage(Package{recipient, street, number, l, "false"});

    this -> ui->locationLineEdit->clear();
    this -> ui->adressLineEdit->clear();
    this -> ui->recipientLineEdit->clear();

    populate_list();
    this -> service.notify();
}

void companyUi::update() {
    populate_list();
}
