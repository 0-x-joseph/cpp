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

    typename MS::iterator it  = ms.begin ();
    typename MS::iterator ite = ms.end ();

    std::cout << "First 20 (forward): ";
    print_first_n (it, ite, 20);

    it  = ms.begin ();
    ite = ms.end ();

    int sum = std::accumulate (it, ite, 0);
    std::cout << "sum: " << sum << std::endl;

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

    int target = ms.top ();
    it         = ms.begin ();
    ite        = ms.end ();
    int cnt    = std::count (it, ite, target);
    std::cout << "count(top=" << target << "): " << cnt << std::endl;

    int probe                   = rand_int (-1000, 1000);
    it                          = ms.begin ();
    ite                         = ms.end ();
    typename MS::iterator found = std::find (it, ite, probe);
    std::cout << "find(" << probe
              << "): " << (found != ite ? "FOUND" : "not found") << std::endl;

    it       = ms.begin ();
    ite      = ms.end ();
    int skip = 100;
    while (it != ite && skip--)
        ++it;
    std::cout << "After skipping 100, next 10: ";
    print_first_n (it, ite, 10);

    MS copy (ms);
    std::cout << "copy.size: " << copy.size () << " | copy.top: " << copy.top ()
              << std::endl;

    MS assigned;
    assigned = ms;
    std::cout << "assigned.size: " << assigned.size ()
              << " | assigned.top: " << assigned.top () << std::endl;

    ms.pop ();
    std::cout << "after pop -> original.top: " << ms.top ()
              << " | copy.top: " << copy.top ()
              << " | assigned.top: " << assigned.top () << std::endl;

    typename MS::iterator cit  = assigned.begin ();
    typename MS::iterator cite = assigned.end ();
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

    {
        MutantStack<int, std::vector<int> > ms;
        ms.push (5);
        ms.push (17);
        ms.push (3);
        fill_random (ms, 10000, -1000, 1000);
        run_test ("MutantStack<int, std::vector<int> >", ms);
    }

    {
        MutantStack<int> ms;
        ms.push (42);
        ms.push (-7);
        ms.push (99);
        fill_random (ms, 10000, 0, 20000);
        run_test ("MutantStack<int, std::deque<int> >", ms);
    }

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
