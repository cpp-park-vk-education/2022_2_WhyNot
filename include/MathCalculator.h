#ifndef MATHCALCULATOR_H
#define MATHCALCULATOR_H

#include "MathExpression.h"

class MathCalculator {
private:
    MathExpression expression;
public:
    MathCalculator() = default;

    explicit MathCalculator(const MathExpression &);

    double Calculate(double);
};


#endif //MATHCALCULATOR_H
