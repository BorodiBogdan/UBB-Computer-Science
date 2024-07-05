//
// Created by Bob on 5/9/2024.
//

#ifndef INC_1ST_QT_PROJECT_CHOOSEMODEWIDGET_H
#define INC_1ST_QT_PROJECT_CHOOSEMODEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QObject>

class ChooseFileTypeWidget : public QWidget {
Q_OBJECT

public:
    explicit ChooseFileTypeWidget(QWidget *parent = nullptr);

    ~ChooseFileTypeWidget() override;
signals:
    void backButtonClickedSignal();
    void CSVFilePathSignal();
    void HTMLFilePathSignal();
    void TXTFilePathSignal();
private:
    QPushButton *CSV;
    QPushButton *HTML;
    QPushButton *TXT;
    QPushButton *backButton;

    friend class Connecter;
};


#endif //INC_1ST_QT_PROJECT_CHOOSEMODEWIDGET_H
