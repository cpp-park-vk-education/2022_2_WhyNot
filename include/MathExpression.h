#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include "MathChecker.h"
#include "MathParser.h"
#include <map>
#include <iostream>

class MathExpression {
private:
    std::string initial;
    std::list<std::string> token_list;
public:
    MathExpression() = default;

    bool SetExpression(const std::string &str);

    std::string GetInitial();

    std::list<std::string> GetPostfix();
};


#endif //MATHEXPRESSION_H
