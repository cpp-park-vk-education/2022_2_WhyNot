#include "Graph.h"

void Graph::Evaluate() {
    for (int i = 0; i < 100; ++i) {
        valueTable.emplace_back(i, calculator.Calculate(i));
    }
}

void Graph::Input() {
    std::string temp;
    MathExpression expression;
    while (!expression.SetExpression(temp)) {
        std::cin >> temp;
    }
    calculator = MathCalculator(expression);
}
