#include <QApplication>
#include "gui.h"
#include "tableViewModel.h"
using namespace std;

int main(int argc, char **argv){
    QApplication a(argc, argv);

    Service serv;
    MyModel *model = new MyModel;
    model->setBacterias(serv.getBacteriaList());

    for(auto &biologist : serv.getBiologistList()){
        gui *myNewGui = new gui(serv, biologist, model);
        myNewGui->show();
    }

    return a.exec();
}