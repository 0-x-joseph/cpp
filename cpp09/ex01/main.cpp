#include "RPN.h"
#include <iostream>

int main (int ac, char** av) {
    if (ac != 2) {
        std::cout << "Usage ./RPN <expression>" << std::endl;
        return (1);
    }
    rpn (av[1]);
    return (0);
}
