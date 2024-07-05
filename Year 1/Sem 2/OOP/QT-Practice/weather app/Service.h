//
// Created by Bob on 5/28/2024.
//

#ifndef WEATHERAPP_SERVICE_H
#define WEATHERAPP_SERVICE_H
#include "Repository.h"

class Service {
private:
    Repository repository;
public:
    vector <Weather> getWeatherListSorted();
    vector <Weather> getWeatherListFiltered(int precipitationProbability);
    vector <Weather> getWeatherAfterAnInterval(int start, string description);
    int getTotalOfHours(int start, string description);
};


#endif //WEATHERAPP_SERVICE_H
