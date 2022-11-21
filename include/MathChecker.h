#ifndef MATHCHECKER_H
#define MATHCHECKER_H

#include "MathExpression.h"

class MathChecker {
private:
    std::string userExpression;
    std::string errorType;
    std::string *operationsList{};
    std::string *functionsList{};
public:
    MathChecker() : operationsList(nullptr), functionsList(nullptr) {}

    MathChecker(std::string *, std::string *);

    bool areTokensCorrect();

    bool areBracketsCorrect();

    bool areMissedOperations();

    bool isTokenCorrect();
};


#endif //MATHCHECKER_H
