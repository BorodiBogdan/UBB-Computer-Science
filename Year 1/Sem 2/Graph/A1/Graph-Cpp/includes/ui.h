#pragma once
#include "graph.h"
#include <fstream>
#include <string>

class Ui
{
public:
    Graph myGraph = Graph(0);

    void readGraph(std::string input_file);
    void DisplayGraph(std::string output_file);
    void startUi();
};