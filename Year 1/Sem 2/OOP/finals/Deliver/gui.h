//
// Created by Bob on 6/28/2024.
//

#ifndef INC_1ST_QT_PROJECT_GUI_H
#define INC_1ST_QT_PROJECT_GUI_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget , public Observer{
Q_OBJECT

public:
    gui(Service &service, Courier &courier);
    ~gui() override;
public slots:
    void populateList();
    void fillComboBox();
    void filterByComboBox();
    void deliverPackage();
    void update() override;
private:
    Ui::gui *ui;
    Service& service;
    Courier &courier;
};


#endif //INC_1ST_QT_PROJECT_GUI_H
