#pragma once
#include <QAbstractTableModel>
#include "Bacteria.h"
#include <vector>

class MyModel : public QAbstractTableModel {
Q_OBJECT
public:
    explicit MyModel(QObject *parent = nullptr);
    void setBacterias(const std::vector<Bacteria>& bacterias);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
private:
    std::vector<Bacteria> bacterias;

};
