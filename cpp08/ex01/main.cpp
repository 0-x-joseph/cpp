#include "Span.h"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <vector>

int main () {
    try {
        Span sp (5);
        sp.addNumber (6);
        sp.addNumber (3);
        sp.addNumber (17);
        sp.addNumber (9);
        sp.addNumber (11);

        std::cout << "Shortest span: " << sp.shortestSpan () << std::endl;
        std::cout << "Longest span : " << sp.longestSpan () << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what () << std::endl;
    }

    try {
        Span sp (1);
        sp.addNumber (42);
        std::cout << sp.shortestSpan () << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what () << std::endl;
    }

    try {
        Span original (5);
        original.addNumber (1);
        original.addNumber (2);
        original.addNumber (3);

        Span copy (original);
        Span assigned (5);
        assigned = original;

        std::cout << "Copy longest span: " << copy.longestSpan () << std::endl;
        std::cout << "Copy shortest span: " << copy.shortestSpan () << std::endl;
        std::cout << "Assigned longest span: " << assigned.longestSpan () << std::endl;
        std::cout << "Assigned shortest span: " << assigned.shortestSpan () << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what () << std::endl;
    }

    try {
        const int N = 10000;
        Span bigSpan (N);

        std::srand (static_cast<unsigned int> (std::time (NULL)));

        for (int i = 0; i < N; ++i) {
            bigSpan.addNumber (std::rand ());
        }

        std::cout << "Shortest span: " << bigSpan.shortestSpan () << std::endl;
        std::cout << "Longest span : " << bigSpan.longestSpan () << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what () << std::endl;
    }

    try {
        std::vector<int> values;
        for (int i = 0; i < 50; ++i) {
            values.push_back (std::rand () % 1000);
        }

        Span rangeSpan (50);
        rangeSpan.addRange (values.begin (), values.end ());

        std::cout << "Shortest span: " << rangeSpan.shortestSpan () << std::endl;
        std::cout << "Longest span : " << rangeSpan.longestSpan () << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what () << std::endl;
    }

    try {
        std::vector<int> values (100, 42);
        Span smallSpan (10);
        smallSpan.addRange (values.begin (), values.end ());
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what () << std::endl;
    }

    try {
        std::vector<int> values (100, 42);
        Span smallSpan (100);
        smallSpan.addRange (values.end (), values.begin ());
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what () << std::endl;
    }

    return 0;
}
