#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
    typedef std::stack<T, Container> stack_type;
    typedef typename Container::iterator iterator;

    MutantStack () : stack_type () {
    }

    MutantStack (const MutantStack<T>& other) : stack_type (other) {
    }

    MutantStack& operator= (const MutantStack<T>& src) {
        stack_type::operator= (src);
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
