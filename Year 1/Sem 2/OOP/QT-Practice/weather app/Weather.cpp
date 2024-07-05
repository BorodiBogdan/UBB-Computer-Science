//
// Created by Bob on 5/28/2024.
//

#include "Weather.h"

Weather::Weather(int start, int end, int temperature, int precipitationProbability, string description) {
    this -> start = start;
    this -> end = end;
    this -> temperature = temperature;
    this -> precipitationProbability = precipitationProbability;
    this -> description = description;
}

int Weather::getStart() {
    return this -> start;
}

int Weather::getEnd() {
    return this -> end;
}

int Weather::getTemperature() {
    return this -> temperature;
}

int Weather::getPrecipitationProbability() {
    return this -> precipitationProbability;
}

string Weather::getDescription() {
    return this -> description;
}
