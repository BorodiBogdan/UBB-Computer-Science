//
// Created by Bob on 6/25/2024.
//

#ifndef MICROBIAL_GUI_H
#define MICROBIAL_GUI_H

#include <QWidget>
#include "Service.h"
#include "tableViewModel.h"
#include <QSortFilterProxyModel>


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

public:
    gui(Service &service, Biologist &biologist, MyModel *model);
    ~gui() override;

private:
    Ui::gui *ui;
    Service &service;
    Biologist &biologist;
    MyModel *tableViewModel;
    QSortFilterProxyModel* myFilterProxyModel;
public slots:
    void populateTableView();
    void populateComboBox();
    void selectionChanged();
    void addButtonPressed();
};


#endif //MICROBIAL_GUI_H
