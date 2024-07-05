#pragma once
#include "service.h"
#include <fstream>
#include <string>

class Ui
{
private:
    Service service;

public:
    void readDirectedGraph(std::string input_file);
    void DisplayGraph(std::string output_file);
    void startUi();
    void readUndirectedGraph(std::string input_file);
    void menuForA1();
    void menuForA2();
    void menuForA3();
    void menuForA4();
};