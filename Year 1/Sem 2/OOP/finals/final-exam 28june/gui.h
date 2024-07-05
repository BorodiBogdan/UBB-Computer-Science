//
// Created by Bob on 6/27/2024.
//

#ifndef PRACTICAL_EXAM_GUI_H
#define PRACTICAL_EXAM_GUI_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget, public Observer {
Q_OBJECT

public:
    ~gui() override;
    gui(Service &serv, Courier &courier);
    void update();
private:
    Ui::gui *ui;
    Service& service;
    Courier& courier;
};


#endif //PRACTICAL_EXAM_GUI_H
