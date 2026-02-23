#include "PmergeMe.h"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

int parse (const std::string& nbr) {
    char* endptr;
    double val = std::strtod (nbr.c_str (), &endptr);
    if (*endptr != '\0' || val < 0)
        throw std::runtime_error (
        "Error: Sequence must contain positive numbers only.");
    return static_cast<int> (val);
}

int main (int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe sequence[...]" << std::endl;
        return (1);
    }
    std::vector<int> seq;
    for (int i = 1; i < ac; i++) {
        try {
            seq.push_back (parse (av[i]));
        } catch (std::exception& e) {
            std::cerr << e.what () << std::endl;
            return (1);
        }
    }
    PmergeMe pmerge_me (seq);
    pmerge_me.run ();
    pmerge_me.display_results (seq);
    return (0);
}
