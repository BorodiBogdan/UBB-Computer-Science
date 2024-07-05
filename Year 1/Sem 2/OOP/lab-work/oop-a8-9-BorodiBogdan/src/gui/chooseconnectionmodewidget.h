//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_CHOOSECONNECTIONMODEWIDGET_H
#define INC_1ST_QT_PROJECT_CHOOSECONNECTIONMODEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class chooseConnectionModeWidget; }
QT_END_NAMESPACE

class chooseConnectionModeWidget : public QWidget {
Q_OBJECT

public:
    explicit chooseConnectionModeWidget(QWidget *parent = nullptr);

    ~chooseConnectionModeWidget() override;
signals:
    void backButtonClickedSignal();
    void userModeSelectedSignal();
    void adminModeSelectedSignal();
private:
    QPushButton *userButton;
    QPushButton *adminButton;
    QPushButton *backButton;
    QPushButton *genreChartButton;

    friend class Connecter;
};


#endif //INC_1ST_QT_PROJECT_CHOOSECONNECTIONMODEWIDGET_H
