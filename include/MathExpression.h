#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include <map>
#include <string>

class MathExpression {
private:
    std::string initial;
    std::string postfix;
    std::map<double, std::string> parameters;
public:
    MathExpression() = default;

    void SetExpression(const std::string &);

    void SetParameters();

    std::string GetExpression();
};


#endif //MATHEXPRESSION_H
