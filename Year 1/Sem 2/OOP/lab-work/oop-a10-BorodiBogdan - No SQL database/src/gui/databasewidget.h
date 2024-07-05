//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_DATABASEWIDGET_H
#define INC_1ST_QT_PROJECT_DATABASEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QObject>


QT_BEGIN_NAMESPACE
namespace Ui { class DataBaseWidget; }
QT_END_NAMESPACE

class DataBaseWidget : public QWidget {
Q_OBJECT

public:
    explicit DataBaseWidget(QWidget *parent = nullptr);

    ~DataBaseWidget() override;
signals:
    void realDataBaseButtonClicked();
    void fileDataBaseButtonClicked();
    void exitButtonClicked();

private:
    QPushButton *FileButton;
    QPushButton *DataBaseButton;
    QPushButton *ExitButton;

    friend  class Connecter;
};


#endif //INC_1ST_QT_PROJECT_DATABASEWIDGET_H
