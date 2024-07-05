//
// Created by Bob on 6/25/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <set>
#include <string>
#include <QMessageBox>
#include "utils.h"
#include "viewwidget.h"


gui::gui(Service &service, Biologist &biologist, MyModel *model): ui(new Ui::gui), service(service), biologist(biologist), tableViewModel(model){
    ui->setupUi(this);
    this ->setWindowTitle(QString::fromStdString(biologist.getName()));
    this -> myFilterProxyModel = new QSortFilterProxyModel();
    this -> myFilterProxyModel->setSourceModel(model);
    this -> ui->bacteriaTableView->setModel(myFilterProxyModel);

    populateComboBox();

   QObject::connect(this -> ui->bacteriaSpeciesComboBox, &QComboBox::currentTextChanged, this, &gui::selectionChanged);
   QObject::connect(this -> ui->addButton, &QPushButton::clicked, this, &gui::addButtonPressed);
   QObject::connect(this ->ui->viewButton, &QPushButton::clicked, this, [&]{
       ViewBacteriaWindow *bctWindow = new ViewBacteriaWindow(service);
       bctWindow->show();
  });
}


gui::~gui() {
    delete ui;
}

void gui::populateTableView() {
    vector <Bacteria> bacteria;
}

void gui::populateComboBox() {
    set <string> s;
    this -> ui->bacteriaSpeciesComboBox->addItem("All");

    for(auto bacteria : biologist.getBacteriaList())
        s.insert(bacteria.getSpecies());

    for(auto x : s){
        this -> ui->bacteriaSpeciesComboBox->addItem(QString::fromStdString(x));
    }
}

void gui::selectionChanged() {
    string text = ui->bacteriaSpeciesComboBox->currentText().toStdString();

    qDebug() << text;

    if(text == "All"){
        this -> myFilterProxyModel->setFilterRegularExpression(QRegularExpression(".*", QRegularExpression::CaseInsensitiveOption));
    }
    else{
        this -> myFilterProxyModel->setFilterRegularExpression(QRegularExpression(QString::fromStdString(text), QRegularExpression::CaseInsensitiveOption));
    }
    this -> myFilterProxyModel->setFilterKeyColumn(1);
}

void gui::addButtonPressed() {
    string name = this -> ui->nameLineEdit->text().toStdString();
    string size = this -> ui->sizeLineEdit->text().toStdString();
    string species = this -> ui->speciesLineEdit->text().toStdString();
    vector<string> diseases = utils::tokenize(",", ui->diseasesLineEdit->text().toStdString());

    for(auto bacteria : service.getBacteriaList())
        if(bacteria.getSpecies() == species && bacteria.getName() == name){
            QMessageBox *newBox = new QMessageBox;
            newBox->setText("Same species and name!!");
            newBox->show();
            return;
        }
    qDebug() << "Added";
    this -> service.addBacteria(Bacteria(name, species, size, diseases));
    this -> tableViewModel->setBacterias(service.getBacteriaList());
}
