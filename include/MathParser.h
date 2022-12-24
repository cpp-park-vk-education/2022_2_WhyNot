#ifndef MATHPARSER_H
#define MATHPARSER_H

#include <string>
#include <list>
#include <stack>

class MathParser {
private:
    std::list<std::string> token_list;
public:
    MathParser() = default;

    bool Parse(const std::string &str);

    static int Priority(std::string);

    void Print();

    std::list<std::string> GetList();
};


#endif //MATHPARSER_H
