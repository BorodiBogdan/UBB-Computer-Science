//
// Created by Bob on 5/10/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userWidget.h" resolved

#include "userwidget.h"
#include "watchlistwidget.h"
#include <QDebug>

userWidget::userWidget(QWidget *parent, Service &service) : QWidget(parent), service(service) {
    auto *userLayout = new QGridLayout;
    QGroupBox *userOptionsGroupBox = createUserOptionsGroupBox();

    QGroupBox *listMoviesByGenre = createListMoviesByGenreBox();

    userLayout->addWidget(userOptionsGroupBox, 0, 0);
    userLayout->addWidget(listMoviesByGenre, 0, 1);
    this->setLayout(userLayout);
}

userWidget::~userWidget() {

}
QGroupBox *userWidget::createUserOptionsGroupBox() {
    //-1 -> no movie genre selected
    this -> indexOfMovie = -1;

    QPushButton *backButton = new QPushButton("BACK");

    QObject::connect(backButton, &QPushButton::clicked, [&](){
        emit userBackButtonSignal();
    });

    QLabel *genreLabel = new QLabel("Enter genre:");

    QLineEdit *genreLineEdit = new QLineEdit(this);
    this -> genreLineEdit = genreLineEdit;

    QHBoxLayout *vboxForGenre = new QHBoxLayout;
    vboxForGenre->addWidget(genreLabel);
    vboxForGenre->addWidget(genreLineEdit);

    QWidget *widgetForGenre = new QWidget;
    widgetForGenre->setLayout(vboxForGenre);

    QPushButton *listMoviesByGenreButton = new QPushButton("List Movies By Genre");

    QObject::connect(listMoviesByGenreButton, &QPushButton::clicked, this, &userWidget::startListMoviesByGenre);

    QPushButton *seeWatchListButton = new QPushButton("See Watch List");

    QObject::connect(seeWatchListButton, &QPushButton::clicked, this, [&](){
        emit openWatchlistSignal();
    });

    QGroupBox *groupBox = new QGroupBox(tr("User Options"));
    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(widgetForGenre);
    vbox->addWidget(listMoviesByGenreButton);
    vbox->addWidget(seeWatchListButton);
    vbox->addWidget(backButton);
    groupBox->setLayout(vbox);

    return groupBox;
}

QGroupBox *userWidget::createListMoviesByGenreBox() {
    QGroupBox *groupBox = new QGroupBox(tr("List Movies By Genre"));
    QPushButton *nextButton = new QPushButton("NEXT");

    QObject::connect(nextButton, &QPushButton::clicked, this, &userWidget::nextMovie);

    QPushButton *addToPlaylistButton = new QPushButton("Add to WatchList");

    QObject::connect(addToPlaylistButton, &QPushButton::clicked, this, &userWidget::addMovieToWatchList);

    QPushButton *seeWatchListInFile = new QPushButton("See watch list in file");

    QObject::connect(seeWatchListInFile, &QPushButton::clicked, this, [&]{
       this -> service.openWatchList();
    });

    QPushButton *exitButton = new QPushButton("EXIT");

    QObject::connect(exitButton, &QPushButton::clicked, this, &userWidget::exitListMovieByGenre);

    QVBoxLayout *vbox = new QVBoxLayout;

    //we need to add the labels
    QLabel *titleLabel = new QLabel("Title:");
    QLabel *genreLabel = new QLabel("Genre:");
    QLabel *trailerLabel = new QLabel("Trailer:");
    QLabel *yearLabel = new QLabel("Year:");
    QLabel *likesLabel = new QLabel("Likes:");

    this->titleLabel = titleLabel;
    this->genreLabel = genreLabel;
    this->trailerLabel = trailerLabel;
    this->yearLabel = yearLabel;
    this->likesLabel = likesLabel;

    vbox->addWidget(titleLabel);
    vbox->addWidget(genreLabel);
    vbox->addWidget(trailerLabel);
    vbox->addWidget(yearLabel);
    vbox->addWidget(likesLabel);

    //buttons
    vbox->addWidget(nextButton);
    vbox->addWidget(addToPlaylistButton);
    vbox->addWidget(seeWatchListInFile);
    vbox->addWidget(exitButton);

    groupBox->setLayout(vbox);

    return groupBox;
}

void userWidget::nextMovie() {
    if(indexOfMovie == -1)
    {
        QMessageBox::critical(this, "Error", "No genre selected!");
        return;
    }

    indexOfMovie++;

    if(indexOfMovie == service.getMoviesByGenre(this->currentlyDisplayedGenre).size())
        indexOfMovie = 0;

    //ShellExecuteA(0, 0, service.getMoviesByGenre(this -> currentlyDisplayedGenre)[indexOfMovie].getTrailer().c_str(), 0, 0, SW_SHOW);

    std::string command = "start " + service.getMoviesByGenre(this -> currentlyDisplayedGenre)[indexOfMovie].getTrailer();
    system(command.c_str());

    this->displayMovie();
}

void userWidget::startListMoviesByGenre() {
    this->currentlyDisplayedGenre = genreLineEdit->text().toStdString();
    vector <Movie> movies = service.getMoviesByGenre(currentlyDisplayedGenre);

    if(movies.empty())
    {
        QMessageBox::critical(this, "Error", "No movies with this genre in the database!");
        return;
    }

    indexOfMovie = 0;
    //we need to display the first movie
    std::string command = "start " + service.getMoviesByGenre(this -> currentlyDisplayedGenre)[0].getTrailer();
    system(command.c_str());
    this->displayMovie();
}

void userWidget::displayMovie() {
    vector <Movie> movies = service.getMoviesByGenre(this -> currentlyDisplayedGenre);

    titleLabel->setText("Title: " + QString::fromStdString(movies[indexOfMovie].getTitle()));
    genreLabel->setText("Genre: " + QString::fromStdString(movies[indexOfMovie].getGenre()));
    trailerLabel->setText("Trailer: " + QString::fromStdString(movies[indexOfMovie].getTrailer()));
    yearLabel->setText("Year of release: " + QString::number(movies[indexOfMovie].getYearOfRelease()));
    likesLabel->setText("Number of likes: " + QString::number(movies[indexOfMovie].getNumberOfLikes()));
}

void userWidget::exitListMovieByGenre() {
    titleLabel->setText("Title: ");
    genreLabel->setText("Genre: ");
    trailerLabel->setText("Trailer: ");
    yearLabel->setText("Year of release: ");
    likesLabel->setText("Number of likes: ");
    this -> indexOfMovie = -1;
}

void userWidget::addMovieToWatchList() {
    Movie movie = service.getMoviesByGenre(this->currentlyDisplayedGenre)[indexOfMovie];

    try {
        service.addMovieToWatchList(movie);
    }
    catch (DuplicateMovieException &exception) {
        QMessageBox::critical(this, "Error", "Movie already in watchlist!");
        return;
    }

    qDebug() << "Movie added to watchlist!";
    emit changeWatchList(service.getWatchList());

    QMessageBox::information(this, "Success", "Movie added to watchlist!");

    this->indexOfMovie++;

    if(indexOfMovie == service.getMoviesByGenre(this->currentlyDisplayedGenre).size())
        indexOfMovie = 0;

    this -> displayMovie();
}
