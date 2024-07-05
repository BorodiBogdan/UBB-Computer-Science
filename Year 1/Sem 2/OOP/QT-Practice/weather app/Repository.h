//
// Created by Bob on 5/28/2024.
//

#ifndef WEATHERAPP_REPOSITORY_H
#define WEATHERAPP_REPOSITORY_H
#include "Weather.h"
#include <vector>

class Repository {
private:
    vector<Weather> weatherList;
public:
    Repository();
    vector<Weather> getWeatherList();
    void readFromFile();
};


#endif //WEATHERAPP_REPOSITORY_H
