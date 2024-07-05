#include "viewwidget.h"
#include <QVBoxLayout>

ViewBacteriaWindow::ViewBacteriaWindow(Service& service, QWidget* parent)
        : QWidget(parent), service(service) {
    this->setup();
    this->displayBacteria();
}

void ViewBacteriaWindow::setup() {
    this->setWindowTitle("View Bacteria");
    this->resize(600, 400);

    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);

    auto* layout = new QVBoxLayout(this);
    layout->addWidget(view);
    this->setLayout(layout);
}

void ViewBacteriaWindow::displayBacteria() {
    std::map<std::string, std::vector<Bacteria>> speciesMap;

    // Collect bacterias by species
    const auto& bacterias = service.getBacteriaList();
    for (const auto& bacterium : bacterias) {
        speciesMap[bacterium.getSpecies()].push_back(bacterium);
    }

    int y = 0;
    // Iterate over each species
    for (const auto& pair : speciesMap) {
        const auto& species = pair.first;
        const auto& speciesBacterias = pair.second;

        auto* textItem = new QGraphicsTextItem(QString::fromStdString(species));
        textItem->setPos(0, y);
        scene->addItem(textItem);

        int x = 0;
        // Iterate over each bacterium of the species
        for (const auto& bacterium : speciesBacterias) {
            auto* circle = new QGraphicsEllipseItem(x, y + 20, 20, 20);
            circle->setBrush(Qt::blue);
            scene->addItem(circle);
            x += 30;
        }
        y += 50;
    }
}
