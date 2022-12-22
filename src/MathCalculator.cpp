#include "MathCalculator.h"

MathCalculator::MathCalculator(MathExpression expr) {
    auto temp = expr.GetPostfix();
    for (const auto &i: temp) {
        list.push_back(i);
    }
    checker = MathChecker(expr.GetPostfix());
}

double MathCalculator::Calculate(double x) {
    double res = 0;
    auto token_list = list;
    for (int i = 0; i < token_list.size(); ++i) {
        res = 0;
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
            token_list.erase(token_list.begin(), token_list.begin() + 1);
            if (operation == "sin") {
                token_list.insert(token_list.begin(), std::to_string(sin(operand1)));
            } else if (operation == "cos") {
                token_list.insert(token_list.begin(), std::to_string(cos(operand1)));
            } else if (operation == "tg") {
                token_list.insert(token_list.begin(), std::to_string(tan(operand1)));
            } else if (operation == "ctg") {
                token_list.insert(token_list.begin(), std::to_string(1 / tan(operand1)));
            } else if (operation == "sqrt") {
                token_list.insert(token_list.begin(), std::to_string(sqrt(operand1)));
            }
            i = 0;
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
            token_list.erase(token_list.begin(), token_list.begin() + 1);
            --i;
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
            token_list.erase(token_list.begin(), token_list.begin() + 2);
            if (operation == "+") {
                token_list.insert(token_list.begin(), std::to_string(operand1 + operand2));
            } else if (operation == "-") {
                token_list.insert(token_list.begin(), std::to_string(operand1 - operand2));
            } else if (operation == "/") {
                token_list.insert(token_list.begin(), std::to_string(operand1 / operand2));
            } else if (operation == "*") {
                token_list.insert(token_list.begin(), std::to_string(operand1 * operand2));
            } else if (operation == "^") {
                token_list.insert(token_list.begin(), std::to_string(pow(operand1, operand2)));
            }
            i = 0;
        } else if (temp == "constant") {
            double operand1;
            switch (token_list[i][0]) {
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
            token_list.erase(token_list.begin(), token_list.begin() + 1);
            token_list.insert(token_list.begin(), std::to_string(operand1));
        }
        return std::stof(token_list[0]);
    }
}