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
                bool negative = false;
                if (token_list[i - 1][0] == '-') {
                    token_list[i - 1].erase(token_list[i - 1].begin(), token_list[i - 1].begin() + 1);
                    negative = true;
                }
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
                if (negative) {
                    operand1 = -operand1;
                }
            } else {
                operand1 = std::stof(token_list[i - 1]);
            }
            auto operation = token_list[i];
            bool negative = false;
            if (operation[0] == '-') {
                operation.erase(operation.begin(), operation.begin() + 1);
                negative = true;
            }
            token_list.erase(token_list.begin() + i - 1, token_list.begin() + i + 1);
            i -= 1;
            if (operation == "sin") {
                operand1 = sin(operand1);
            } else if (operation == "cos") {
                operand1 = cos(operand1);
            } else if (operation == "tg") {
                operand1 = tan(operand1);
            } else if (operation == "ctg") {
                operand1 = 1/tan(operand1);
            } else if (operation == "sqrt") {
                operand1 = sqrt(operand1);
            } else if (operation == "abs") {
                operand1 = std::abs(operand1);
            } else if (operation == "ln") {
                operand1 = log(operand1);
            }
            if (negative) {
                operand1 = -operand1;
            }
            token_list.insert(token_list.begin() + i, std::to_string(operand1));
        } else if (temp == "operation") {
            double operand1;
            if (checker.whatToken(token_list[i - 2]) == "constant") {
                bool negative = false;
                if (token_list[i - 2][0] == '-') {
                    token_list[i - 2].erase(token_list[i - 2].begin(), token_list[i - 2].begin() + 1);
                    negative = true;
                }
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
                if (negative) {
                    operand1 = -operand1;
                }
            } else {
                bool negative = false;
                operand1 = std::stof(token_list[i - 2]);
            }
            double operand2;
            if (checker.whatToken(token_list[i - 1]) == "constant") {
                bool negative = false;
                if (token_list[i - 1][0] == '-') {
                    token_list[i - 1].erase(token_list[i - 1].begin(), token_list[i - 1].begin() + 1);
                    negative = true;
                }
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
                if (negative) {
                    operand1 = -operand1;
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
        } else if (token_list[i] == "x" or token_list[i] == "-x") {
            bool negative = false;
            if (token_list[i][0] == '-') {
                token_list[i].erase(token_list[i].begin(), token_list[i].begin() + 1);
                negative = true;
            }
            double operand1 = x;
            if (negative) {
                operand1 = -operand1;
            }
            token_list[i] = std::to_string(operand1);
        }
    }
    return std::stof(token_list[0]);
}
