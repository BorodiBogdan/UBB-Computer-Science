//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_IDEASWIDGET_H
#define RESEARCH_IDEASWIDGET_H

#include <QWidget>
#include "Service.h"
#include "tableViewModel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ideasWidget; }
QT_END_NAMESPACE

class ideasWidget : public QWidget {
Q_OBJECT

public:
    ideasWidget(Researcher &researcher, Service &service, IdeasTableModel *model, QWidget *parent = nullptr);

    ~ideasWidget() override;
public slots:
    void updateList();
    void updateIdeas();
    void saveButtonClicked();
private:
    Ui::ideasWidget *ui;
    IdeasTableModel *model;
    Researcher &researcher;
    Service &service;
    vector<Ideea> changedIdeas;
};


#endif //RESEARCH_IDEASWIDGET_H
