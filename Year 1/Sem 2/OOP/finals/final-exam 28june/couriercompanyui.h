//
// Created by Bob on 6/28/2024.
//

#ifndef PRACTICAL_EXAM_COURIERCOMPANYUI_H
#define PRACTICAL_EXAM_COURIERCOMPANYUI_H

#include <QWidget>
#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class courierCompanyUi; }
QT_END_NAMESPACE

class courierCompanyUi : public QWidget, public Observer{
Q_OBJECT

public:
    courierCompanyUi(Service &s);
    ~courierCompanyUi() override;
    void update();
public slots:
    void add();
private:
    Service& serv;
    Ui::courierCompanyUi *ui;
};


#endif //PRACTICAL_EXAM_COURIERCOMPANYUI_H
