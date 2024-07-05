//
// Created by Bob on 5/10/2024.
//

#ifndef INC_1ST_QT_PROJECT_USERWIDGET_H
#define INC_1ST_QT_PROJECT_USERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QBoxLayout>
#include <QGridLayout>
#include <QTableWidget>
#include "../../includes/service/service.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

class userWidget : public QWidget {
Q_OBJECT

public:
    explicit userWidget(QWidget *parent, Service &service);


    QGroupBox *createUserOptionsGroupBox();
    QGroupBox *createListMoviesByGenreBox();
    ~userWidget() override;
signals:
    void userBackButtonSignal();
    void openWatchlistSignal();
    void changeWatchList(vector<Movie> movieList);
public slots:
    void startListMoviesByGenre();
    void nextMovie();
    void exitListMovieByGenre();
    void displayMovie();
    void addMovieToWatchList();
private:
    int indexOfMovie;
    QLabel *titleLabel, *genreLabel, *trailerLabel, *yearLabel,  *likesLabel;
    QLineEdit *genreLineEdit;
    Service &service;
    std::string currentlyDisplayedGenre;
};


#endif //INC_1ST_QT_PROJECT_USERWIDGET_H
