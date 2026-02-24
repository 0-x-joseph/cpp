#ifndef __PMERGEME__
#define __PMERGEME__

#include <list>
#include <utility>
#include <vector>

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

#endif /* __PMERGEME__ */
