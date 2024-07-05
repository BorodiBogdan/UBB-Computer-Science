//
// Created by Bob on 5/28/2024.
//
#include "Service.h"
#include "test.h"
#include <iostream>
#include <cassert>

void testGetCarsByManufacturer(){
    Service service;

    for(int i = 1; i <= 5; ++i){
        service.addCar(Car("test", "test", i, "test"));
        assert(service.getCarsByManufacturer("test").size() == i);
    }

    service.addCar(Car("df", "gh" ,4,""));

    assert(service.getCarsByManufacturer("test").size() == 5);
    assert(service.getCarsByManufacturer("df").size() == 1);
    assert(service.getCarsByManufacturer("dsdff").size() == 0);

    std::cout << "All tests done\n";
}