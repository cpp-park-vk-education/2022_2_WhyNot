#include "MathParser.h"

MathParser::MathParser(const std::string &) {}

MathParser::~MathParser() {
    delete token_list;
}

