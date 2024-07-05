#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"

class IdeasTableModel :
        public QAbstractTableModel
{
public:
    Service& controller;

    IdeasTableModel(Service& controller): controller{controller} {}

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void addIdea(Ideea& idea);
    void reviseIdea(int indexOfIdea);
    void updateIdeea(Ideea &ideea);

    std::vector<Ideea> acceptedIdeas(Researcher researcher);
};

