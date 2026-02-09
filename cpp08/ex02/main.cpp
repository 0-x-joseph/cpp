#include "MutantStack.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

static int rand_int (int lo, int hi) {
    return lo + (std::rand () % (hi - lo + 1));
}

template <typename MS> static void fill_random (MS& ms, int n, int lo, int hi) {
    for (int i = 0; i < n; ++i)
        ms.push (rand_int (lo, hi));
}

template <typename It> static void print_first_n (It it, It ite, int n) {
    int i = 0;
    while (it != ite && i < n) {
        std::cout << *it << " ";
        ++it;
        ++i;
    }
    std::cout << std::endl;
}

template <typename MS> static void run_test (const std::string& name, MS& ms) {
    std::cout << "\n========== " << name << " ==========\n";

    std::cout << "size: " << ms.size () << std::endl;
    std::cout << "top:  " << ms.top () << std::endl;

    // Forward iteration
    typename MS::iterator it  = ms.begin ();
    typename MS::iterator ite = ms.end ();

    std::cout << "First 20 (forward): ";
    print_first_n (it, ite, 20);

    // Reverse iteration
    typename MS::reverse_iterator rit  = ms.rbegin ();
    typename MS::reverse_iterator rite = ms.rend ();
    std::cout << "First 20 (reverse): ";
    print_first_n (rit, rite, 20);

    // Re-get forward iterators (we consumed them above)
    it  = ms.begin ();
    ite = ms.end ();

    // Algorithms on iterators
    int sum = std::accumulate (it, ite, 0);
    std::cout << "sum: " << sum << std::endl;

    // min/max (manual to stay C++98-friendly and avoid edge cases)
    it     = ms.begin ();
    int mn = *it;
    int mx = *it;
    for (; it != ite; ++it) {
        if (*it < mn)
            mn = *it;
        if (*it > mx)
            mx = *it;
    }
    std::cout << "min: " << mn << " | max: " << mx << std::endl;

    // count occurrences of some value
    int target = ms.top ();
    it         = ms.begin ();
    ite        = ms.end ();
    int cnt    = std::count (it, ite, target);
    std::cout << "count(top=" << target << "): " << cnt << std::endl;

    // find a random value
    int probe                   = rand_int (-1000, 1000);
    it                          = ms.begin ();
    ite                         = ms.end ();
    typename MS::iterator found = std::find (it, ite, probe);
    std::cout << "find(" << probe
              << "): " << (found != ite ? "FOUND" : "not found") << std::endl;

    // Range walk: skip first 100, print next 10
    it       = ms.begin ();
    ite      = ms.end ();
    int skip = 100;
    while (it != ite && skip--)
        ++it;
    std::cout << "After skipping 100, next 10: ";
    print_first_n (it, ite, 10);

    // Copy constructor
    MS copy (ms);
    std::cout << "copy.size: " << copy.size () << " | copy.top: " << copy.top ()
              << std::endl;

    // Assignment
    MS assigned;
    assigned = ms;
    std::cout << "assigned.size: " << assigned.size ()
              << " | assigned.top: " << assigned.top () << std::endl;

    // Mutate original and show copies unaffected (sanity)
    ms.pop ();
    std::cout << "after pop -> original.top: " << ms.top ()
              << " | copy.top: " << copy.top ()
              << " | assigned.top: " << assigned.top () << std::endl;

    // Iterate assigned again (ensure iterators still work post assignment)
    typename MS::const_iterator cit  = assigned.begin ();
    typename MS::const_iterator cite = assigned.end ();
    std::cout << "assigned first 10 (const iter): ";
    int i = 0;
    while (cit != cite && i < 10) {
        std::cout << *cit << " ";
        ++cit;
        ++i;
    }
    std::cout << std::endl;
}

int main () {
    std::srand (static_cast<unsigned int> (std::time (NULL)));

    // Test 1: vector container
    {
        MutantStack<int, std::vector<int> > ms;
        ms.push (5);
        ms.push (17);
        ms.push (3);
        fill_random (ms, 10000, -1000, 1000);
        run_test ("MutantStack<int, std::vector<int> >", ms);
    }

    // Test 2: deque container (default stack container)
    {
        MutantStack<int> ms;
        ms.push (42);
        ms.push (-7);
        ms.push (99);
        fill_random (ms, 10000, 0, 20000);
        run_test ("MutantStack<int, std::deque<int> >", ms);
    }

    // Test 3: list container
    {
        MutantStack<int, std::list<int> > ms;
        ms.push (1);
        ms.push (2);
        ms.push (3);
        fill_random (ms, 10000, -50, 50);
        run_test ("MutantStack<int, std::list<int> >", ms);
    }

    return 0;
}
