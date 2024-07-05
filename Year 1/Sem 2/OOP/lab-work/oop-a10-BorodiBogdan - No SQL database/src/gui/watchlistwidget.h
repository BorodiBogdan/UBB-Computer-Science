//
// Created by Bob on 5/17/2024.
//

#ifndef INC_1ST_QT_PROJECT_WATCHLISTWIDGET_H
#define INC_1ST_QT_PROJECT_WATCHLISTWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <vector>
#include "../../includes/domain/domain.h"
#include "tableView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class watchListWidget; }
QT_END_NAMESPACE

class watchListWidget : public QWidget {
Q_OBJECT

public:
    explicit watchListWidget(QWidget *parent = nullptr);

    ~watchListWidget() override;
public slots:
    void updateTableInformationBasedOnDataBase(vector<Movie>);
signals:
    void watchListBackButtonSignal();
private:
    MyModel *tableWidget;
};


#endif //INC_1ST_QT_PROJECT_WATCHLISTWIDGET_H
