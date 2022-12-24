#include "MathParser.h"
#include <iostream>

int MathParser::Priority(std::string str) {
    if (str.length() > 1) {
        return 4;
    } else if (str[0] == '^') {
        return 3;
    } else if (str[0] == '/' || str[0] == '*') {
        return 2;
    } else if (str[0] == '+' || str[0] == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool MathParser::Parse(const std::string &str) {
    std::stack<std::string> st;
    for (int i = 0; i < str.length(); ++i) {
        std::string temp;
        /*if (str[i] == ' ') {
            continue;
        }*/
        if ((str[i] >= 'a' and str[i] <= 'z') or (str[i] == '-' and str[i + 1] >= 'a' and str[i + 1] <= 'z' and (i == 0 or (str[i - 1] != ')' and (str[i - 1] < 'a' or str[i - 1] > 'z'))))) {
            if (str[i] == '-') {
                temp += '-';
                ++i;
            }
            do {
                temp += str[i++];
            } while (str[i] >= 'a' and str[i] <= 'z');
            if (temp.length() == 1) {
                token_list.push_back(temp);
            } else {
                st.push(temp);
            }
            --i;
        } else if ((str[i] >= '0' and str[i] <= '9') or (str[i] == '-' and str[i + 1] >= '1' and str[i + 1] <= '9' and (i == 0 or (str[i - 1] != ')' and (str[i - 1] < '0' or str[i - 1] > '9'))))) {
            if (str[i] == '-') {
                temp += '-';
                ++i;
            }
            if (str[i] == '0') {
                temp += str[i++];
                if (str[i] >= '0' and str[i] <= '9') {
                    return false;
                } else {
                    token_list.push_back(temp);
                    //token_list.emplace_back(" ");
                    --i;
                }
            } else {
                do {
                    temp += str[i++];
                } while (str[i] >= '0' and str[i] <= '9');
                token_list.push_back(temp);
                //token_list.emplace_back(" ");
                --i;
            }
        } else if (str[i] == '(') {
            st.push(std::string(1, str[i]));
        } else if (str[i] == ')') {
            while (st.top()[0] != '(') {
                token_list.push_back(st.top());
                //token_list.emplace_back(" ");
                st.pop();
                if (st.empty()) {
                    return false;
                }
            }
            st.pop();
        } else {
            while (!st.empty() && Priority(std::string(1, str[i])) <= Priority(st.top())) {
                token_list.push_back(st.top());
                //token_list.emplace_back(" ");
                st.pop();
            }
            st.push(std::string(1, str[i]));
        }
    }
    while (!st.empty()) {
        token_list.push_back(st.top());
        //token_list.emplace_back(" ");
        st.pop();
    }
    return true;
}

void MathParser::Print() {
    for (const auto &i: token_list) {
        std::cout << i << ' ';
    }
}

std::list<std::string> MathParser::GetList() {
    return token_list;
}
