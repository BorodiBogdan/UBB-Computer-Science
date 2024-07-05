#include "tableView.h"

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent) {}

void MyModel::setMovies(const std::vector<Movie>& movies) {
    beginResetModel();
    this->movies = movies;
    endResetModel();
}

int MyModel::rowCount(const QModelIndex& parent) const {
    return movies.size();
}

int MyModel::columnCount(const QModelIndex& parent) const {
    return 5;
}

QVariant MyModel::data(const QModelIndex& index, int role) const {
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return {};

    const Movie movie = movies.at(index.row());

    switch (index.column()) {
        case 0: return QString::fromStdString(movie.getTitle());
        case 1: return QString::fromStdString(movie.getGenre());
        case 2: return QString::fromStdString(movie.getTrailer());
        case 3: return movie.getYearOfRelease();
        case 4: return movie.getNumberOfLikes();
        default: return QVariant();
    }
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Title";
            case 1: return "Genre";
            case 2: return "Trailer Link";
            case 3: return "Release Year";
            case 4: return "Likes";
            default: return QVariant();
        }
    }
    return QVariant();
}
