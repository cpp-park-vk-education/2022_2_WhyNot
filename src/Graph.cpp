#include "Graph.h"

void Graph::Evaluate() {
    double i = 0;
    while (i < (double)25) {
        valueTable.emplace_back(i, calculator.Calculate(i));
        i += 0.05;
    }
}

void Graph::Input() {
    std::string temp;
    MathExpression expression;
    while (!expression.SetExpression(temp)) {
        getline(std::cin, temp);
    }
    calculator = MathCalculator(expression);
}
