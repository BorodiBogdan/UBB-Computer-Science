#include "tableViewModel.h"
#include <algorithm>

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent) {}

void MyModel::setBacterias(const std::vector<Bacteria> &bacterias) {
    beginResetModel();
    this->bacterias = bacterias;
    endResetModel();
}

int MyModel::rowCount(const QModelIndex& parent) const {
    return bacterias.size();
}

int MyModel::columnCount(const QModelIndex& parent) const {
    return 4;
}

QVariant MyModel::data(const QModelIndex& index, int role) const {
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return {};

    const Bacteria bacteria = bacterias[index.row()];

    switch (index.column()) {
        case 0: return QString::fromStdString(bacteria.getName());
        case 1: return QString::fromStdString(bacteria.getSpecies());
        case 2: return QString::fromStdString(to_string(bacteria.getSize()));
        case 3: return QString::fromStdString(bacteria.deseaseToString());
        default: return QVariant();
    }
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "Name";
            case 1: return "Species";
            case 2: return "Size";
            case 3: return "Desease List";
            default: return QVariant();
        }
    }
    return QVariant();
}
bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role != Qt::EditRole)
        return false;

    Bacteria &bacteria = bacterias[index.row()];

    switch(index.column()) {
        case 0: bacteria.setName(value.toString().toStdString()); break;
        case 1: bacteria.setSpecies(value.toString().toStdString()); break;
        case 2: bacteria.setSize(value.toString().toStdString()); break;
        case 3:  break;
        default: return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}