#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
    typedef typename Container::iterator iterator;

    MutantStack () : std::stack<T, Container> () {
    }

    MutantStack (const MutantStack<T>& other)
    : std::stack<T, Container> (other) {
    }

    MutantStack& operator= (const MutantStack<T>& src) {
        std::stack<T, Container>::operator= (src);
        return *this;
    }

    ~MutantStack () {
    }

    iterator begin () {
        return this->c.begin ();
    }
    iterator end () {
        return this->c.end ();
    }
};

#endif /* __MUTANTSTACK__ */
