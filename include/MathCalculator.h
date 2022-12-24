#ifndef MATHCALCULATOR_H
#define MATHCALCULATOR_H

#include "MathExpression.h"
#include <cmath>

class MathCalculator {
private:
    std::vector<std::string> list;
    MathChecker checker;
public:
    MathCalculator() = default;

    explicit MathCalculator(MathExpression);

    double Calculate(double);
};


#endif //MATHCALCULATOR_H
