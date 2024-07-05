#include "gui.h"
#include <QApplication>
#include "tableViewModel.h"

int main(int argc, char **argv){
    QApplication a(argc, argv);

    Service serv;
    IdeasTableModel *model = new IdeasTableModel(serv);

    for(auto &researcher : serv.getResearchers()){
        gui *newGui = new gui(serv, researcher, model);
        newGui->show();
    }
    return a.exec();
}