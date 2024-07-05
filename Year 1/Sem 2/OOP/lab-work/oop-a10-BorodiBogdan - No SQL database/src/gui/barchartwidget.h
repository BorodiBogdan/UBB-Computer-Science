//
// Created by Bob on 5/19/2024.
//

#ifndef INC_1ST_QT_PROJECT_BARCHARTWIDGET_H
#define INC_1ST_QT_PROJECT_BARCHARTWIDGET_H

#include <QWidget>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include "../../includes/service/service.h"
#include <QtCharts/QBarSet>
#include <QBoxLayout>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>
#include "../../includes/domain/domain.h"
#include <string>
#include <map>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class barChartWidget; }
QT_END_NAMESPACE

class barChartWidget : public QWidget {
Q_OBJECT

public:
    explicit barChartWidget(QWidget *parent, Service &service);

    QChart* generateChart();
    QBarSeries *generateUpdatedSeries();
    ~barChartWidget() override;
public slots:
    void updateChart();
signals:
    void chartBackButton();
private:
    Service& service;
    QChart *genreChart;
    QChartView *genreChartView;
};


#endif //INC_1ST_QT_PROJECT_BARCHARTWIDGET_H
