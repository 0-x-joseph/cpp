#include "BitcoinExchange.hpp"
#include <iostream>

int main (int ac, char** av) {
    if (ac != 2) {
        std::cout << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.run (av[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what () << std::endl;
        return 1;
    }

    return 0;
}
