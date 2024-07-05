//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_ADMINWIDGET_H
#define INC_1ST_QT_PROJECT_ADMINWIDGET_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <vector>
#include <QWidget>
#include "../../includes/service/service.h"
#include <QLabel>
#include <QTableWidget>
#include "../../includes/domain/domain.h"
#include "../../includes/utils/Utils.h"

namespace CONSTANT
{
    const int TABLE_COLUMN_COUNT = 5;
    const int DEFAULT_SPACING = 20;
    const int TITLE_COLUMN = 0;
    const int GENRE_COLUMN = 1;
    const int YEAR_COLUMN = 2;
    const int LIKES_COLUMN = 3;
    const int TRAILER_COLUMN = 4;
    const int TITLE_COLUMN_WIDTH = 300;
}

class AdminWidget : public QWidget
{
Q_OBJECT
private:
    QPushButton *backButton;
    QTableWidget *movieTableWidget;
    Service &service;
    QLineEdit *movieTitleInput, *movieGenreInput, *movieYearOfReleaseInput, *movieLikesCountInput, *movieTrailerInput;
public:
    AdminWidget(QWidget *parent, Service &service);
    QTableWidget *createTableWidget();
    ~AdminWidget(){};
    QHBoxLayout * createButtonsForManagingMovies();
    QHBoxLayout * createMovieTitle();
    QHBoxLayout * createMovieGenreLayout();
    QHBoxLayout * createMovieYearOfReleaseLayout();
    QHBoxLayout * createLikesCountLayout();
    QHBoxLayout * createMovieTrailerLayout();
    void insertIntoTable(const Movie &movie);
signals:
    void adminBackButtonSignal();
    void changeWatchList(vector<Movie> movieList);
    void updateGenreChartSignal();
public slots:
    void addMovieAdminWidget();
    void deleteMovieAdminWidget();
    void updateMovieAdminWidget();
    void modifyTableInformationBasedOnDataBase();
    void executeUndo();
    void executeRedo();
};

#endif // ADMINWIDGET_H