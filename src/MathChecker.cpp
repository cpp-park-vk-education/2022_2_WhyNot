#include "MathChecker.h"

bool MathChecker::areTokensCorrect() {
    for (const auto &i: token_list) {
        if (!isTokenCorrect(i)) {
            return false;
        }
    }
    return true;
}

bool MathChecker::areMissedOperandsOrOperations() {
    std::string temp;
    int operand_count = 0;
    for (const auto &i: token_list) {
        temp = whatToken(i);
        if (temp == "space") {
            continue;
        }
        if (temp == "operand" or temp == "constant") {
            ++operand_count;
        } else if (temp == "function" and operand_count == 1) {
            operand_count = 0;
        } else if (temp == "operation" and operand_count == 2) {
            operand_count = 0;
        } else {
            return true;
        }
    }
    return false;
}

bool MathChecker::isTokenCorrect(const std::string &str) {
    /*if (std::find(operationsList.begin(), operationsList.end(), str) != operationsList.end()) {
        std::cout << "oper\n";
    }
    if (std::find(functionsList.begin(), functionsList.end(), str) != functionsList.end()) {
        std::cout << "func\n";
    }
    if (std::all_of(str.begin(), str.end(), ::isdigit)) {
        std::cout << "digit\n";
    }
    if (str[0] == ' ') {
        std::cout << "space\n";
    }*/
    return (std::find(operationsList.begin(), operationsList.end(), str) != operationsList.end())
           or (std::find(functionsList.begin(), functionsList.end(), str) != functionsList.end())
           or (std::find(constantsList.begin(), constantsList.end(), str) != constantsList.end())
           or (std::all_of(str.begin(),
                           str.end(),
                           ::isdigit)) or str[0] == ' ';
}

MathChecker::MathChecker(std::list<std::string> list) : token_list(std::move(list)) {
    operationsList = {"+", "-", "*", "/", "^"};
    functionsList = {"sin", "cos", "tg", "ctg", "sqrt"};
    constantsList = {"e", "x", "pi"};
}

std::string MathChecker::Convert() {
    std::string temp;
    for (const auto &i: token_list) {
        temp += i;
    }
    return temp;
}

std::string MathChecker::whatToken(const std::string &str) {
    if (std::find(operationsList.begin(), operationsList.end(), str) != operationsList.end()) {
        return "operation";
    } else if (std::find(functionsList.begin(), functionsList.end(), str) != functionsList.end()) {
        return "function";
    } else if (std::find(constantsList.begin(), constantsList.end(), str) != constantsList.end()) {
        return "constant";
    } else if (str == " ") {
        return "space";
    } else {
        return "operand";
    }
}

bool MathChecker::CheckCorrectness() {
    return areTokensCorrect() and !areMissedOperandsOrOperations();
}

std::list<std::string> MathChecker::GetList() {
    return token_list;
}
