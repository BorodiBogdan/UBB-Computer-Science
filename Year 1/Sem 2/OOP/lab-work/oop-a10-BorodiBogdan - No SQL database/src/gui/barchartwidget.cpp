//
// Created by Bob on 5/19/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_barChartWidget.h" resolved

#include "barchartwidget.h"

barChartWidget::barChartWidget(QWidget *parent, Service &service): QWidget(), service(service){
    this -> genreChart = this -> generateChart();

    QChartView *chartView = new QChartView;
    this->genreChartView = chartView;

    chartView->setChart(this -> genreChart);
    QVBoxLayout *vlayout = new QVBoxLayout;

    vlayout->addWidget(chartView);

    QPushButton *button = new QPushButton("BACK");
    vlayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, this, [&]{
        qDebug() << "Chart back button clicked!";
        emit chartBackButton();
    });

    this->setLayout(vlayout);
}
barChartWidget::~barChartWidget() {

}

QChart *barChartWidget::generateChart() {
    QBarSeries *series = this -> generateUpdatedSeries();
    map<string, bool> isGenre;

    auto chart = new QChart;
    chart->addSeries(series);

    chart->setTitle("Genre Bar Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Genre"};
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;

    int maxValue = 0;

    for(auto movie : service.getMovies())
        if(service.getMoviesByGenre(movie.getGenre()).size() > maxValue)
            maxValue = service.getMoviesByGenre(movie.getGenre()).size();

    axisY->setRange(0,maxValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    return chart;
}

QBarSeries *barChartWidget::generateUpdatedSeries() {
    QBarSeries *series = new QBarSeries;
    map<string, bool> isGenre;

    for(auto movie : service.getMovies()) {
        if(isGenre[movie.getGenre()] == true)
            continue;

        isGenre[movie.getGenre()] = true;

        QString genre = QString::fromStdString(movie.getGenre());
        auto set = new QBarSet(genre);
        *set << service.getMoviesByGenre(movie.getGenre()).size();
        series->append(set);
    }

    return series;
}

void barChartWidget::updateChart() {
    this -> genreChartView->setChart(this->generateChart());
}
