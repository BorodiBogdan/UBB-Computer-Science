//
// Created by Bob on 6/26/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <QMessageBox>


gui::gui(Service &service, Researcher &researcher, IdeasTableModel *model): service(service), researcher(researcher), model(model), ui(new Ui::gui) {
    ui ->setupUi(this);

    this -> ui->IdeeaTableView->setModel(model);

    this ->setWindowTitle(QString::fromStdString(researcher.getPosition()));
    this -> ui->positionGroupBox->setTitle(QString::fromStdString(researcher.getName()));

    if(this -> researcher.getPosition() != "senior"){
        this -> ui->acceptPushButton->hide();
        this -> ui->saveAllButton->hide();
    }

    QObject::connect(this -> ui->addButton, &QPushButton::clicked, this, &gui::addButtonPressed);
    QObject::connect(this -> ui->acceptPushButton, &QPushButton::clicked, this, &gui::acceptButtonPressed);
    QObject::connect(this -> ui->developPushButton, &QPushButton::clicked, this, &gui::developButtonPressed);
    QObject::connect(this -> ui->saveAllButton, &QPushButton::clicked, this, [&]{
        this -> service.saveAllToFile();
    });
};


gui::~gui() {
    delete ui;
}

void gui::addButtonPressed() {
    string description = this -> ui->descriptionLineEdit->text().toStdString();
    string title = this -> ui->titleLineEdit->text().toStdString();
    int duration = this -> ui->durationLineEdit->text().toInt();

    if(duration <= 0 or duration > 3){
        QMessageBox::warning(this, "Error", "Invalid duration");
        return;
    }

    Ideea *id = new Ideea(title, description, "proposed", researcher.getName(), duration);

    this -> ui->descriptionLineEdit->clear();
    this -> ui->titleLineEdit->clear();
    this -> ui->durationLineEdit->clear();


    this -> model->addIdea(*id);
    this -> researcher.addIdea(*id);
}

void gui::acceptButtonPressed() {
    int index = ui->IdeeaTableView->currentIndex().row();
    try
    {
        model->reviseIdea(index);
    }
    catch (std::exception& e)
    {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void gui::filterIdeas() {

}

void gui::developButtonPressed() {
    bool ok = 0;

    for(auto ideas : researcher.getIdeas())
        if(ideas.getStatuts() == "accepted")
            ok = 1;

    if(ok == 0){
        QMessageBox::warning(this, "Error", "No accepted ideas");
        return;
    }

    ideasWidget *id = new ideasWidget(researcher, service, model);
    id -> show();
}

void gui::saveAllButton() {

}
