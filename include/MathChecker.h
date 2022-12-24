#ifndef MATHCHECKER_H
#define MATHCHECKER_H

#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <iostream>

class MathChecker {
private:
    std::string errorType;
    std::list <std::string> token_list;
    std::list <std::string> operationsList;
    std::list <std::string> functionsList;
    std::list <std::string> constantsList;
public:
    MathChecker() = default;

    explicit MathChecker(std::list<std::string>);

    bool areTokensCorrect();

    bool areMissedOperandsOrOperations();

    bool isTokenCorrect(const std::string& );

    std::string Convert();

    std::string whatToken(const std::string&);

    bool CheckCorrectness();

    std::list<std::string> GetList();
};


#endif //MATHCHECKER_H
