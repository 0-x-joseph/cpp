#include "PmergeMe.h"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

static std::vector<size_t> jacobsthal_sequence (size_t n) {
    std::vector<size_t> jacob;
    jacob.push_back (1);
    jacob.push_back (3);
    while (jacob.back () < n) {
        jacob.push_back (jacob.back () + 2 * jacob[jacob.size () - 2]);
    }
    std::vector<size_t> seq;
    size_t last_val = 1;
    for (size_t i = 0; i < jacob.size (); ++i) {
        size_t current_val = jacob[i];

        size_t k = (current_val < n) ? current_val : n;

        while (k > last_val) {
            seq.push_back (k);
            --k;
        }
        last_val = current_val;
    }
    return seq;
}

void PmergeMe::ford_jhonson_vec (std::vector<int>& container) {
    if (container.size () < 2)
        return;
    int straggler = container.size () % 2 != 0 ? container.back () : -1;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size () - 1; i += 2) {
        if (container[i] < container[i + 1])
            pairs.push_back ({ container[i + 1], container[i] });
        else
            pairs.push_back ({ container[i], container[i + 1] });
    }

    std::sort (pairs.begin (), pairs.end ());

    std::vector<int> winners, losers;
    for (size_t i = 0; i < pairs.size (); i++) {
        winners.push_back (pairs[i].first);
        losers.push_back (pairs[i].second);
    }
    winners.insert (winners.begin (), losers[0]);

    std::vector<size_t> jacob_seq = jacobsthal_sequence (losers.size ());

    for (size_t i = 0; i < jacob_seq.size (); i++) {
        size_t idx_to_insert = jacob_seq[i] - 1;
        if (idx_to_insert < losers.size () && idx_to_insert > 0) {
            int target = losers[idx_to_insert];
            std::vector<int>::iterator it =
            std::lower_bound (winners.begin (), winners.end (), target);
            winners.insert (it, target);
        }
    }

    if (straggler != -1) {
        std::vector<int>::iterator it =
        std::lower_bound (winners.begin (), winners.end (), straggler);
        winners.insert (it, straggler);
    }
    container = winners;
}

void PmergeMe::ford_jhonson_list (std::list<int>& container) {
    if (container.size () < 2)
        return;
    int straggler = container.size () % 2 != 0 ? container.back () : -1;

    std::vector<std::pair<int, int> > pairs;
    std::list<int>::iterator it = container.begin ();
    while (it != container.end ()) {
        int first = *it;
        ++it;
        if (it != container.end ()) {
            int second = *it;
            if (first < second)
                pairs.push_back ({ second, first });
            else
                pairs.push_back ({ first, second });
            ++it;
        }
    }

    std::sort (pairs.begin (), pairs.end ());

    std::vector<int> winners, losers;
    for (size_t i = 0; i < pairs.size (); i++) {
        winners.push_back (pairs[i].first);
        losers.push_back (pairs[i].second);
    }
    winners.insert (winners.begin (), losers[0]);

    std::vector<size_t> jacob_seq = jacobsthal_sequence (losers.size ());

    for (size_t i = 0; i < jacob_seq.size (); i++) {
        size_t idx_to_insert = jacob_seq[i] - 1;
        if (idx_to_insert < losers.size () && idx_to_insert > 0) {
            int target = losers[idx_to_insert];
            std::vector<int>::iterator it =
            std::lower_bound (winners.begin (), winners.end (), target);
            winners.insert (it, target);
        }
    }

    if (straggler != -1) {
        std::vector<int>::iterator it =
        std::lower_bound (winners.begin (), winners.end (), straggler);
        winners.insert (it, straggler);
    }
    std::list<int> newlist (winners.begin (), winners.end ());
    container = newlist;
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
    size_t size = original.size () < 11 ? original.size () : 10;
    std::cout << "Before: ";
    for (size_t i = 0; i < size; i++) {
        std::cout << original[i] << (i == size - 1 ? "" : " ");
    }
    if (size != original.size ())
        std::cout << " [...]";
    size = _vec.size () < 11 ? _vec.size () : 10;
    std::cout << "\nAfter:  ";
    for (size_t i = 0; i < size; i++) {
        std::cout << _vec[i] << (i == size - 1 ? "" : " ");
    }
    if (size != _vec.size ())
        std::cout << " [...]";

    std::cout << "\nTime to process a range of " << _vec.size ()
              << " elements with std::vector : " << std::fixed
              << std::setprecision (5) << _time_vec << " us";
    std::cout << "\nTime to process a range of " << _list.size ()
              << " elements with std::list   : " << std::fixed
              << std::setprecision (5) << _time_list << " us" << std::endl;
}
