//
// Created by Bob on 6/26/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ideasWidget.h" resolved

#include "ideaswidget.h"
#include "ui_ideasWidget.h"



ideasWidget::ideasWidget(Researcher  &researcher,  Service &service, IdeasTableModel *model, QWidget *parent) :researcher(researcher), service(service), model(model), ui(new Ui::ideasWidget) {
    ui->setupUi(this);
    //set header for table
     QStringList header;
     header << "Title" << "Description" << "Status" << "Creator" << "Duration";
     ui->ideaTableWidget->setHorizontalHeaderLabels(header);
     ui->ideaTableWidget->setColumnCount(5);
     ui->ideaTableWidget->setColumnWidth(0, 200);

     //update list
    updateList();

    //when a cell is modified
    //we must change the idea status
    QObject::connect(ui->saveButton, &QPushButton::clicked, this, &ideasWidget::saveButtonClicked);

    QObject::connect(ui->ideaTableWidget, &QTableWidget::cellChanged, this, [&]{
        int row = ui->ideaTableWidget->currentRow();
        int column = ui->ideaTableWidget->currentColumn();
        if(column == 1){
            string text = ui->ideaTableWidget->item(row, column)->text().toStdString();
            researcher.getIdeas()[row].setDescription(text);
            this -> changedIdeas.push_back(researcher.getIdeas()[row]);
        }
    });

}
ideasWidget::~ideasWidget() {
    delete ui;
}

void ideasWidget::updateList() {
    this ->ui->ideaTableWidget->clear();


    //add ideas to table
    for(auto idea : researcher.getIdeas())
        if(idea.getStatuts() == "accepted")
        {
            ui->ideaTableWidget->insertRow(ui->ideaTableWidget->rowCount());
            int row = ui->ideaTableWidget->rowCount() - 1;
            ui->ideaTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(idea.getTitle())));
            ui->ideaTableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(idea.getDescription())));
            ui->ideaTableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(idea.getStatuts())));
            ui->ideaTableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(idea.getCreator())));
            ui->ideaTableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(idea.getDuration())));
            //set column 2 to be modified
            //just COLUMN 2

            ui->ideaTableWidget->item(row, 2)->setFlags(ui->ideaTableWidget->item(row, 2)->flags() | Qt::ItemIsEditable);
        }
}

void ideasWidget::updateIdeas() {

}

void ideasWidget::saveButtonClicked() {
    for(auto &idea : this -> changedIdeas) {
        model->updateIdeea(idea);
        this -> service.saveIdeeaToFile(idea);
    }
}
