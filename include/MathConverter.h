#ifndef MATHCONVERTER_H
#define MATHCONVERTER_H

#include "MathExpression.h"

class MathConverter {
private:
    std::map<std::string, double> precedence;
public:
    MathConverter() = default;

    std::string ConvertToPost(const std::string &);
};

#endif //MATHCONVERTER_H
