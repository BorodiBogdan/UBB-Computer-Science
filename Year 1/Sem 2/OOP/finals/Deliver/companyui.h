//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_COMPANYUI_H
#define INC_1ST_QT_PROJECT_COMPANYUI_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class companyUi; }
QT_END_NAMESPACE

class companyUi : public QWidget, public Observer{
Q_OBJECT

public:
    companyUi(Service &service, QWidget *parent = nullptr);

    ~companyUi() override;
    void update() override;
public slots:
    void populate_list();
    void add_package();
private:
    Ui::companyUi *ui;
    Service &service;
};


#endif //INC_1ST_QT_PROJECT_COMPANYUI_H
