//
// Created by Bob on 5/9/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminWidget.h" resolved


#include "adminwidget.h"
#include <QMessageBox>
#include <QShortcut>
using namespace CONSTANT;

AdminWidget::AdminWidget(QWidget *parent, Service &service) : QWidget(parent), service(service)
{
    QHBoxLayout *adminLayout = new QHBoxLayout;
    QVBoxLayout *movieInformation = new QVBoxLayout;

    auto undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    connect(undoShortcut, &QShortcut::activated, this, &AdminWidget::executeUndo);

    auto redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);
    connect(redoShortcut, &QShortcut::activated, this, &AdminWidget::executeRedo);

    this -> backButton = new QPushButton("BACK");
    auto *backButtonLayout = new QVBoxLayout;
    auto *seeGenreChartButton = new QPushButton("See genre chart");

    backButtonLayout->addWidget(seeGenreChartButton);
    backButtonLayout->addWidget(backButton);

    QObject::connect(this->backButton, &QPushButton::clicked,[&](){
        emit  this -> adminBackButtonSignal();
    });

    QObject::connect(seeGenreChartButton, &QPushButton::clicked, this, [&]{
        emit updateGenreChartSignal();
    });

    QHBoxLayout *movieTitleGroup = createMovieTitle();
    QHBoxLayout *movieGenreGroup = createMovieGenreLayout();
    QHBoxLayout *movieYearGroup = createMovieYearOfReleaseLayout();
    QHBoxLayout *movieLikesGroup = createLikesCountLayout();
    QHBoxLayout *movieTrailerGroup = createMovieTrailerLayout();
    QHBoxLayout *buttons = createButtonsForManagingMovies();

    movieInformation->setSpacing(DEFAULT_SPACING);
    movieInformation->addLayout(movieTitleGroup);
    movieInformation->addLayout(movieGenreGroup);
    movieInformation->addLayout(movieYearGroup);
    movieInformation->addLayout(movieLikesGroup);
    movieInformation->addLayout(movieTrailerGroup);

    movieInformation->addLayout(buttons);
    movieInformation->addLayout(backButtonLayout);
    adminLayout->addLayout(movieInformation);

    QTableWidget *tableWidget = this->createTableWidget();

    adminLayout->addWidget(tableWidget);
    this->setLayout(adminLayout);
}

QHBoxLayout *AdminWidget::createButtonsForManagingMovies()
{
    QHBoxLayout *buttons = new QHBoxLayout();
    QPushButton *addMovie = new QPushButton("Add Movie", this);

    QObject::connect(addMovie, &QPushButton::clicked, this, &AdminWidget::addMovieAdminWidget);

    QPushButton *deleteMovie = new QPushButton("Delete Movie", this);

    QObject::connect(deleteMovie, &QPushButton::clicked, this, &AdminWidget::deleteMovieAdminWidget);

    QPushButton *updateMovie = new QPushButton("Update Movie", this);

    QObject::connect(updateMovie, &QPushButton::clicked, this, &AdminWidget::updateMovieAdminWidget);

    QPushButton *undo = new QPushButton("Undo", this);

    QObject::connect(undo, &QPushButton::clicked, this, &AdminWidget::executeUndo);

    QPushButton *redo = new QPushButton("Redo", this);

    QObject::connect(redo, &QPushButton::clicked, this, &AdminWidget::executeRedo);

    buttons->addWidget(addMovie);
    buttons->addWidget(deleteMovie);
    buttons->addWidget(updateMovie);
    buttons->addWidget(undo);
    buttons->addWidget(redo);

    return buttons;
}

QHBoxLayout *AdminWidget::createMovieTitle()
{
    QLabel *movieTitle = new QLabel("Title of Movie", this);
    QLineEdit *movieTitleInput = new QLineEdit(this);

    this->movieTitleInput= movieTitleInput;

    QHBoxLayout *movieTitleGroup = new QHBoxLayout();
    movieTitleGroup->addWidget(movieTitle);
    movieTitleGroup->addWidget(movieTitleInput);

    return movieTitleGroup;
}

QHBoxLayout *AdminWidget::createMovieGenreLayout()
{
    QLabel *movieGenre = new QLabel("Genre of Movie", this);
    QLineEdit *movieGenreInput = new QLineEdit(this);

    this->movieGenreInput = movieGenreInput;

    QHBoxLayout *movieGenreGroup = new QHBoxLayout();
    movieGenreGroup->addWidget(movieGenre);
    movieGenreGroup->addWidget(movieGenreInput);

    return movieGenreGroup;
}

QHBoxLayout *AdminWidget::createMovieYearOfReleaseLayout()
{
    QLabel *movieYear = new QLabel("Year of Release", this);
    QLineEdit *movieYearInput = new QLineEdit(this);

    this->movieYearOfReleaseInput = movieYearInput;

    QHBoxLayout *movieYearGroup = new QHBoxLayout();
    movieYearGroup->addWidget(movieYear);
    movieYearGroup->addWidget(movieYearInput);

    return movieYearGroup;
}

QHBoxLayout *AdminWidget::createLikesCountLayout()
{
    QLabel *movieLikes = new QLabel("Likes", this);
    QLineEdit *movieLikesInput = new QLineEdit(this);

    this -> movieLikesCountInput = movieLikesInput;

    QHBoxLayout *movieLikesGroup = new QHBoxLayout();
    movieLikesGroup->addWidget(movieLikes);
    movieLikesGroup->addWidget(movieLikesInput);

    return movieLikesGroup;
}

QHBoxLayout *AdminWidget::createMovieTrailerLayout()
{
    QLabel *movieTrailer = new QLabel("Trailer", this);
    QLineEdit *movieTrailerInput = new QLineEdit(this);

    this -> movieTrailerInput = movieTrailerInput;

    QHBoxLayout *movieTrailerGroup = new QHBoxLayout();
    movieTrailerGroup->addWidget(movieTrailer);
    movieTrailerGroup->addWidget(movieTrailerInput);

    return movieTrailerGroup;
}

QTableWidget *AdminWidget::createTableWidget() {
    QTableWidget *tableWidget = new QTableWidget();
    this->movieTableWidget = tableWidget;
    QStringList header = {"Title", "Genre", "Year of Release", "Number of Likes", "Trailer"};
    tableWidget->setColumnCount(TABLE_COLUMN_COUNT);
    tableWidget->setColumnWidth(TITLE_COLUMN, TITLE_COLUMN_WIDTH);
    tableWidget->setHorizontalHeaderLabels(header);

    for (auto movie: service.getMovies())
       this->insertIntoTable(movie);


    return tableWidget;
}

void AdminWidget::addMovieAdminWidget() {
    std::string title = this->movieTitleInput->text().toStdString();
    Utils::trimWhiteSpaces(title);

    std::string genre = this->movieGenreInput->text().toStdString();
    Utils::trimWhiteSpaces(genre);

    int yearOfRelease = this->movieYearOfReleaseInput->text().toInt();
    int likes = this->movieLikesCountInput->text().toInt();

    std::string trailer = this->movieTrailerInput->text().toStdString();
    Utils::trimWhiteSpaces(trailer);

    Movie movieToBeAdded = Movie(title, genre, trailer, yearOfRelease, likes);

    try {
        service.addMovie(movieToBeAdded);
    }
    catch (DuplicateMovieException &exception) {
        QMessageBox::critical(this, "Error", exception.what());
        return;
    }

    this->insertIntoTable(movieToBeAdded);
    this->movieTrailerInput->clear();
    this->movieYearOfReleaseInput->clear();
    this->movieLikesCountInput->clear();
    this->movieGenreInput->clear();
    this->movieTitleInput->clear();
}

void AdminWidget::insertIntoTable(const Movie &movie) {
    QTableWidget *tableWidget = this->movieTableWidget;
    int rowCount = tableWidget->rowCount();

    tableWidget->insertRow(rowCount);
    tableWidget->setItem(rowCount, TITLE_COLUMN, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
    tableWidget->setItem(rowCount, GENRE_COLUMN, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
    tableWidget->setItem(rowCount, YEAR_COLUMN, new QTableWidgetItem(QString::number(movie.getYearOfRelease())));
    tableWidget->setItem(rowCount, LIKES_COLUMN, new QTableWidgetItem(QString::number(movie.getNumberOfLikes())));
    tableWidget->setItem(rowCount, TRAILER_COLUMN,
                         new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
}

void AdminWidget::deleteMovieAdminWidget() {
    std::string title = this->movieTitleInput->text().toStdString();
    Utils::trimWhiteSpaces(title);

    try {
        service.deleteMovie(title);
    }
    catch (RepositoryException &exception) {
        QMessageBox::critical(this, "Error", exception.what());
        return;
    }
    emit changeWatchList(service.getWatchList());

    QTableWidget *tableWidget = this->movieTableWidget;

    for (int i = 0; i < tableWidget->rowCount(); i++) {
        std::string titleOfMovie = tableWidget->item(i, TITLE_COLUMN)->text().toStdString();
        Utils::trimWhiteSpaces(titleOfMovie);

        if (titleOfMovie == title) {
            tableWidget->removeRow(i);
            break;
        }
    }
    this->movieTrailerInput->clear();
    this->movieYearOfReleaseInput->clear();
    this->movieLikesCountInput->clear();
    this->movieGenreInput->clear();
    this->movieTitleInput->clear();
}

void AdminWidget::updateMovieAdminWidget() {
    std::string title = this->movieTitleInput->text().toStdString();
    Utils::trimWhiteSpaces(title);

    std::string genre = this->movieGenreInput->text().toStdString();
    Utils::trimWhiteSpaces(genre);

    int yearOfRelease = this->movieYearOfReleaseInput->text().toInt();
    int likes = this->movieLikesCountInput->text().toInt();

    std::string trailer = this->movieTrailerInput->text().toStdString();
    Utils::trimWhiteSpaces(trailer);

    Movie movieToBeUpdated = Movie(title, genre, trailer, yearOfRelease, likes);

    try {
        service.updateMovie(movieToBeUpdated);
    }
    catch (RepositoryException &exception) {
        QMessageBox::critical(this, "Error", exception.what());
        return;
    }

    emit changeWatchList(service.getWatchList());
    QTableWidget *tableWidget = this->movieTableWidget;

    for (int i = 0; i < tableWidget->rowCount(); i++) {
        std::string titleOfMovie = tableWidget->item(i, TITLE_COLUMN)->text().toStdString();
        Utils::trimWhiteSpaces(titleOfMovie);

        if (titleOfMovie == title) {
            tableWidget->item(i, TITLE_COLUMN)->setText(QString::fromStdString(title));
            tableWidget->item(i, GENRE_COLUMN)->setText(QString::fromStdString(genre));
            tableWidget->item(i, YEAR_COLUMN)->setText(QString::number(yearOfRelease));
            tableWidget->item(i, LIKES_COLUMN)->setText(QString::number(likes));
            tableWidget->item(i, TRAILER_COLUMN)->setText(QString::fromStdString(trailer));
            break;
        }
    }

    this->movieTrailerInput->clear();
    this->movieYearOfReleaseInput->clear();
    this->movieLikesCountInput->clear();
    this->movieGenreInput->clear();
    this->movieTitleInput->clear();
}

void AdminWidget::modifyTableInformationBasedOnDataBase() {
    while(this->movieTableWidget->rowCount() > 0)
        this->movieTableWidget->removeRow(0);

    for (auto movie: service.getMovies())
        this->insertIntoTable(movie);
}

void AdminWidget::executeRedo() {
    try {
        this->service.executeRedo();
        this->modifyTableInformationBasedOnDataBase();
    }
    catch (UndoRedoException &e){
        QMessageBox::critical(this, "Error", e.what());
        return;
    }
}

void AdminWidget::executeUndo() {
    try {
        this->service.executeUndo();
        this->modifyTableInformationBasedOnDataBase();
    }
    catch (UndoRedoException &e){
        QMessageBox::critical(this, "Error", e.what());
        return;
    }
}
