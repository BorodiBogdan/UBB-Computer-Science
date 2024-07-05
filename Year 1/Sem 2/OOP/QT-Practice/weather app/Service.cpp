//
// Created by Bob on 5/28/2024.
//

#include "Service.h"
#include <algorithm>

vector<Weather> Service::getWeatherListSorted() {
    vector <Weather> wList = this -> repository.getWeatherList();

    sort(wList.begin(), wList.end(), [](Weather a, Weather b)->bool{
       return a.getStart() < b.getStart();
    });

    return wList;
}

vector<Weather> Service::getWeatherListFiltered(int precipitationProbability) {
    vector <Weather> wList;

    for(auto w : this -> repository.getWeatherList()){
        if(w.getPrecipitationProbability() < precipitationProbability)
            wList.push_back(w);
    }
    return wList;
}

vector<Weather> Service::getWeatherAfterAnInterval(int start, string description) {
    vector <Weather> wList;

    for(auto w : this -> repository.getWeatherList())
        if(start <= w.getEnd() && w.getDescription() == description)
            wList.push_back(w);

    return wList;
}

int Service::getTotalOfHours(int start, string description) {
    int sum = 0;

    for(auto w : this -> repository.getWeatherList())
        if(start <= w.getEnd() && w.getDescription() == description)
            sum += w.getEnd() - max(w.getStart(), start);

    return sum;
}
