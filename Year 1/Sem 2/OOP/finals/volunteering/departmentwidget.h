//
// Created by Bob on 6/23/2024.
//

#ifndef INC_1ST_QT_PROJECT_DEPARTMENTWIDGET_H
#define INC_1ST_QT_PROJECT_DEPARTMENTWIDGET_H

#include <QWidget>
#include "department.h"
#include "volunteer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DepartMentWidget; }
QT_END_NAMESPACE

class DepartMentWidget : public QWidget {
Q_OBJECT

public:
    explicit DepartMentWidget(QWidget *parent = nullptr);
    explicit DepartMentWidget(department givenDepartment, vector<volunteer> volunteerList);

    ~DepartMentWidget() override;

private:
    Ui::DepartMentWidget *ui;
};


#endif //INC_1ST_QT_PROJECT_DEPARTMENTWIDGET_H
