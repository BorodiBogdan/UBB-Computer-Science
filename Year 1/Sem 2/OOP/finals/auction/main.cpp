#include <QApplication>
#include <QDebug>
#include "guiwidget.h"
#include <QPushButton>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

   controller myController;
   for(auto user : myController.getUsers()){
       qDebug() << user.getName();
       guiWidget *gui = new guiWidget(myController, user);

       gui->show();
   }

    return app.exec();
}
