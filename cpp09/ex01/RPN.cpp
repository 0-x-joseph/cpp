#include "RPN.h"
#include <cctype>
#include <iostream>
#include <sstream>

void rpn (const std::string& expr) {
    std::stack<int> s;
    std::stringstream ss (expr);
    std::string token;

    while (ss >> token) {
        if (token.length () == 1 && std::isdigit (token[0])) {
            s.push (token[0] - '0');
        }

        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size () < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int lhs = s.top ();
            s.pop ();
            int rhs = s.top ();
            s.pop ();
            if (token == "+")
                s.push (rhs + lhs);
            else if (token == "-")
                s.push (rhs - lhs);
            else if (token == "*")
                s.push (rhs * lhs);
            else if (token == "/") {
                if (rhs == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return;
                }

                s.push (rhs / lhs);
            }
        } else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if (s.size () != 1)
        std::cerr << "Error" << std::endl;
    else
        std::cout << s.top () << std::endl;
}
