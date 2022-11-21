#ifndef MATHPARSER_H
#define MATHPARSER_H

#include "MathExpression.h"

class MathParser {
private:
    std::list <std::string> token_list{};
public:
    MathParser() = default;

    explicit MathParser(const std::string &);
};


#endif //MATHPARSER_H
