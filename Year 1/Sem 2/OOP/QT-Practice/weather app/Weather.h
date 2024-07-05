//
// Created by Bob on 5/28/2024.
//

#ifndef WEATHERAPP_WEATHER_H
#define WEATHERAPP_WEATHER_H
#include <string>
using namespace std;

class Weather {
private:
    int start, end, temperature, precipitationProbability;
    string description;
public:
    Weather(int start, int end, int temperature, int precipitationProbability, string description);
    int getStart();
    int getEnd();
    int getTemperature();
    int getPrecipitationProbability();
    string getDescription();
};


#endif //WEATHERAPP_WEATHER_H
