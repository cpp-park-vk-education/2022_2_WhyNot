#ifndef MATHCHECKER_H
#define MATHCHECKER_H

#include "MathExpression.h"

class MathChecker {
private:
    std::string userExpression;
    std::string errorType;
    std::list <std::string> operationsList;
    std::list <std::string> functionsList;
public:
    MathChecker() = default;

    bool areTokensCorrect();

    bool areBracketsCorrect();

    bool areMissedOperations();

    bool isTokenCorrect();
};


#endif //MATHCHECKER_H
