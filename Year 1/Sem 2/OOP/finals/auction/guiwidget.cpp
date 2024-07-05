#include "guiwidget.h"
#include "ui_guiWidget.h"
#include "utils.h"
#include <QMessageBox>
#include <QList>
#include<tuple>
#include <unistd.h>


guiWidget::~guiWidget() {
    delete ui;
}

guiWidget::guiWidget(controller &service, User user) : service(service), user(user), ui(new Ui::guiWidget) {
    ui->setupUi(this);
    this -> service.addObserver(this);
    this ->setWindowTitle(QString::fromStdString(user.getName()));

    for(auto item : service.getItems()){
        ui->itemList->addItem(QString::fromStdString(item.getName() + " " + item.getCategory() + " " + to_string(item.getPrice())));

        ui->itemComboBox->addItem(QString::fromStdString(item.getCategory()));

    }
    qDebug() << user.getType();
    if(user.getType() == "administrator") {
        this->adminCredidential = true;
        qDebug() << adminCredidential;
    }
    else{
        this -> adminCredidential = false;
    }

    QObject::connect(ui->itemComboBox, &QComboBox::currentTextChanged, this, &guiWidget::comboBoxSelectionChanged);
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &guiWidget::addButtonClicked);
    QObject::connect(ui->itemList, &QListWidget::itemSelectionChanged, this, &guiWidget::showOffers);
    QObject::connect(ui->bidButton, &QPushButton::clicked, this, &guiWidget::bidUser);
}

void guiWidget::comboBoxSelectionChanged() {
    this->ui->itemList->clear();
    string category = ui->itemComboBox->currentText().toStdString();

    for(auto item : this -> service.getItems())
        if(item.getCategory() == category)
            ui->itemList->addItem(QString::fromStdString(item.getName() + " " + item.getCategory() + " " + to_string(item.getPrice())));

}

void guiWidget::addButtonClicked() {
    if(this -> adminCredidential == false)
        return;

    string name = this -> ui->itemNameLineEdit->text().toStdString();
    string category = this -> ui->categoryLineEdit->text().toStdString();
    int price = this -> ui->itemPriceLineEdit->text().toInt();
    utils u;

    if(name == "" or price <= 0){
        QMessageBox *msg = new QMessageBox();
        msg->setText("Error!");
        msg->show();
        return;
    }
    vector <string> list = u.tokenize(",", ui->offerListLineEdit->text().toStdString());
    vector<tuple<string, string, string>> offerListTuple;

    for(int i = 0; i < list.size(); i += 3){
        tuple<string, string, string> t(list[i], list[i + 1], list[i + 2]);
        offerListTuple.push_back(t);
    }

    Item itemToBeAdded = Item(name, category, price, offerListTuple);

    this -> service.addItem(itemToBeAdded);

    ui->itemComboBox->addItem(QString::fromStdString(itemToBeAdded.getCategory()));
    this -> service.notifyAllObservervables();
}

void guiWidget::showOffers() {
    QList<QListWidgetItem *> it = this->ui->itemList->selectedItems();

    if(it.size() == 0)
        return;

    QListWidgetItem *item = it.first();

    utils u;
    string name = u.tokenize(" ", it.first()->text().toStdString())[0];

    Item item1 = this -> service.getItemByName(name);
    vector<tuple<string, string, string>> itemOffers = item1.getOffers();

    sort(itemOffers.begin(), itemOffers.end(), [](tuple<string, string, string> a, tuple<string, string, string> b) -> bool{
        return  get<1>(a) < get<2>(b);
    });
    this -> ui->offerListWidget->clear();

    for(auto offer : itemOffers){
        this -> ui->offerListWidget->addItem(QString::fromStdString(get<0>(offer) + " " + get<1>(offer) + " " + get<2>(offer)));
    }
}

void guiWidget::bidUser() {
    if(adminCredidential == true)
        return;

    QList<QListWidgetItem *> it = this->ui->itemList->selectedItems();
    QListWidgetItem *item = it.first();

    utils u;
    string name = u.tokenize(" ", it.first()->text().toStdString())[0];

    int price = this -> ui->bidLineEdit->text().toInt();
    tuple <string , string , string> t(to_string(user.getId()), to_string(price), "2024.06.24");
    Item myItem = this -> service.getItemByName(name);
    qDebug() << myItem.getPrice();

    if(myItem.getPrice() > price){
        QMessageBox *msg = new QMessageBox();
        qDebug() << "sunt aici";
        msg->setText("Error!");
        msg->show();
        return;
    }

    this -> service.updatePrice(name, price);
    this -> service.addOffer(t, name);

    this -> service.notifyAllObservervables();
}

void guiWidget::update() {
    this -> comboBoxSelectionChanged();
    this -> showOffers();
    qDebug() << "Updating...";
}
