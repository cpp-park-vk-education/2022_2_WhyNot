#ifndef GRAPH_H
#define GRAPH_H

#include "MathCalculator.h"
#include <vector>

class Graph {
private:
    std::string color;
    std::vector <std::pair<double, double>> valueTable;
    MathCalculator calculator;
public:
    Graph() = default;

    void Evaluate();

    void Input();
};


#endif //GRAPH_H
