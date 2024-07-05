//
// Created by Bob on 6/26/2024.
//

#ifndef RESEARCH_GUI_H
#define RESEARCH_GUI_H

#include <QWidget>
#include "Service.h"
#include "tableViewModel.h"
#include <QSortFilterProxyModel>
#include "ideaswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
    Q_OBJECT

public:
    gui(Service &service, Researcher& researcher, IdeasTableModel *model);

    ~gui() override;
public slots:
    void addButtonPressed();
    void acceptButtonPressed();
    void developButtonPressed();
    void filterIdeas();
    void saveAllButton();
private:
    Ui::gui *ui;
    Service &service;
    Researcher &researcher;
    IdeasTableModel *model;
    QSortFilterProxyModel *myFilterProxyModel;

};


#endif //RESEARCH_GUI_H
