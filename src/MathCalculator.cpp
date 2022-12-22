#include "MathCalculator.h"

MathCalculator::MathCalculator(MathExpression expr) {
    auto temp = expr.GetPostfix();
    for (const auto &i: temp) {
        list.push_back(i);
    }
    checker = MathChecker(expr.GetPostfix());
}

double MathCalculator::Calculate(double x) {
    auto token_list = list;
    for (int i = 0; i < token_list.size(); ++i) {
        auto temp = checker.whatToken(token_list[i]);
        if (temp == "function") {
            double operand1;
            if (checker.whatToken(token_list[i - 1]) == "constant") {
                switch (token_list[i - 1][0]) {
                    case 'x':
                        operand1 = x;
                        break;
                    case 'e':
                        operand1 = M_E;
                        break;
                    case 'p':
                        operand1 = M_PI;
                        break;
                }
            } else {
                operand1 = std::stof(token_list[i - 1]);
            }
            auto operation = token_list[i];
            token_list.erase(token_list.begin() + i - 1, token_list.begin() + i + 1);
            i -= 1;
            if (operation == "sin") {
                token_list.insert(token_list.begin() + i, std::to_string(sin(operand1)));
            } else if (operation == "cos") {
                token_list.insert(token_list.begin() + i, std::to_string(cos(operand1)));
            } else if (operation == "tg") {
                token_list.insert(token_list.begin() + i, std::to_string(tan(operand1)));
            } else if (operation == "ctg") {
                token_list.insert(token_list.begin() + i, std::to_string(1 / tan(operand1)));
            } else if (operation == "sqrt") {
                token_list.insert(token_list.begin() + i, std::to_string(sqrt(operand1)));
            }
        } else if (temp == "operation") {
            double operand1;
            if (checker.whatToken(token_list[i - 2]) == "constant") {
                switch (token_list[i - 2][0]) {
                    case 'x':
                        operand1 = x;
                        break;
                    case 'e':
                        operand1 = M_E;
                        break;
                    case 'p':
                        operand1 = M_PI;
                        break;
                }
            } else {
                operand1 = std::stof(token_list[i - 2]);
            }
            double operand2;
            if (checker.whatToken(token_list[i - 1]) == "constant") {
                switch (token_list[i - 1][0]) {
                    case 'x':
                        operand2 = x;
                        break;
                    case 'e':
                        operand2 = M_E;
                        break;
                    case 'p':
                        operand2 = M_PI;
                        break;
                }
            } else {
                operand2 = std::stof(token_list[i - 1]);
            }
            auto operation = token_list[i];
            token_list.erase(token_list.begin() + i - 2, token_list.begin() + i + 1);
            i -= 2;
            if (operation == "+") {
                token_list.insert(token_list.begin() + i, std::to_string(operand1 + operand2));
            } else if (operation == "-") {
                token_list.insert(token_list.begin() + i, std::to_string(operand1 - operand2));
            } else if (operation == "/") {
                token_list.insert(token_list.begin() + i, std::to_string(operand1 / operand2));
            } else if (operation == "*") {
                token_list.insert(token_list.begin() + i, std::to_string(operand1 * operand2));
            } else if (operation == "^") {
                token_list.insert(token_list.begin() + i, std::to_string(pow(operand1, operand2)));
            }
        }
    }
    return std::stof(token_list[0]);
}
