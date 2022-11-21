#ifndef GRAPH_H
#define GRAPH_H

#include "MathCalculator.h"
#include <vector>

class Graph {
private:
    std::string color;
    std::vector <std::pair<double, double>> valueTable;
    MathExpression expression;
public:
    Graph() = default;

    Graph(const MathExpression&, const std::string&);

    void Evaluate();

    void UpdateExpression(const std::string&);
};


#endif //GRAPH_H
