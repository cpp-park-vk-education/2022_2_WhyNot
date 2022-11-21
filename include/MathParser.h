#ifndef MATHPARSER_H
#define MATHPARSER_H

#include "MathExpression.h"

class MathParser {
private:
    std::string *token_list{};
public:
    MathParser() : token_list(nullptr) {}

    explicit MathParser(const std::string &);

    ~MathParser();
};


#endif //MATHPARSER_H
