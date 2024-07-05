//
// Created by Bob on 6/27/2024.
//

#ifndef TEST_GUI_H
#define TEST_GUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
    Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr);

    ~gui() override;

private:
    Ui::gui *ui;
};


#endif //TEST_GUI_H
