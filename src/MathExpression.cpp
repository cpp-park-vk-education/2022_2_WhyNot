#include "MathExpression.h"

bool MathExpression::SetExpression(const std::string &str) {
    if(str.empty()) {
        return false;
    }
    initial = str;
    MathParser parser;
    parser.Parse(initial);
    MathChecker checker(std::move(parser.GetList()));
    if (!checker.CheckCorrectness()) {
        return false;
    }
    token_list = std::move(checker.GetList());
    return true;
}

std::string MathExpression::GetInitial() {
    return initial;
}

std::list<std::string> MathExpression::GetPostfix() {
    return token_list;
}
