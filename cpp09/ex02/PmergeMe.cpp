#include "PmergeMe.h"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

/*
class PmergeMe {
    private:
    std::vector<int> _vec;
    std::list<int> _list;
    double _time_vec;
    double _time_list;

    void ford_jhonson_vec (std::vector<int>& container);
    void ford_jhonson_list (std::list<int>& container);

    public:
    PmergeMe ();
    PmergeMe (const std::vector<int>& input);
    PmergeMe (const PmergeMe& other);
    PmergeMe& operator= (const PmergeMe& other);
    ~PmergeMe ();

    void run ();
    void display_results (const std::vector<int>& original) const;
};
*/

void PmergeMe::ford_jhonson_vec (std::vector<int>& container) {
    // TODO: Implement Ford Jhonson algorithm for vector
    std::sort (container.begin (), container.end ());
}

void PmergeMe::ford_jhonson_list (std::list<int>& container) {
    // TODO: Implement Ford Jhonson algorithm for linked list
    container.sort ();
}

PmergeMe::PmergeMe () {
}

PmergeMe::PmergeMe (const std::vector<int>& input)
: _vec (input), _list (input.begin (), input.end ()), _time_vec (0), _time_list (0) {
}

PmergeMe::PmergeMe (const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& other) {
    if (this != &other) {
        _vec       = other._vec;
        _list      = other._list;
        _time_vec  = other._time_vec;
        _time_list = other._time_list;
    }
    return *this;
}
PmergeMe::~PmergeMe () {
}

void PmergeMe::run () {
    clock_t start = clock ();
    ford_jhonson_vec (_vec);
    _time_vec = static_cast<double> (clock () - start) / CLOCKS_PER_SEC * 1000000;

    start = clock ();
    ford_jhonson_list (_list);
    _time_list = static_cast<double> (clock () - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::display_results (const std::vector<int>& original) const {
    std::cout << "Before: ";
    for (size_t i = 0; i < original.size (); i++) {
        std::cout << original[i] << (i == original.size () - 1 ? "" : " ");
    }
    std::cout << "\nAfter:  ";
    for (size_t i = 0; i < _vec.size (); i++) {
        std::cout << _vec[i] << (i == _vec.size () - 1 ? "" : " ");
    }

    std::cout << "\nTime to process a range of " << _vec.size ()
              << " elements with std::vector : " << std::fixed
              << std::setprecision (5) << _time_vec << " us";
    std::cout << "\nTime to process a range of " << _list.size ()
              << " elements with std::list   : " << std::fixed
              << std::setprecision (5) << _time_list << " us" << std::endl;
}
