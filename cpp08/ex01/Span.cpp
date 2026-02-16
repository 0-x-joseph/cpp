#include "Span.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span () : _capacity (0) {
}

Span::Span (unsigned int size) : _capacity (size) {
}

Span::Span (const Span& src) {
    *this = src;
}

Span& Span::operator= (const Span& other) {
    if (this != &other) {
        _capacity = other._capacity;
        _span     = other._span;
    }
    return *this;
}

Span::~Span () {
}

void Span::addNumber (int num) {
    if (_span.size () >= _capacity)
        throw std::logic_error ("Span is full");
    _span.push_back (num);
}

int Span::shortestSpan () const {
    if (_capacity < 2 || _span.size () < 2)
        throw std::logic_error ("Not enough elements to compute shortest span");
    std::vector<int> copy = _span;
    std::sort (copy.begin (), copy.end ());
    int shortest = copy[1] - copy[0];
    for (size_t i = 0; i < copy.size () - 1; i++) {
        int diff = copy[i + 1] - copy[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan () const {
    if (_capacity < 2 || _span.size () < 2)
        throw std::logic_error ("Not enough elements to compute longest span");
    int max, min;
    max = *std::max_element (_span.begin (), _span.end ());
    min = *std::min_element (_span.begin (), _span.end ());
    return (max - min);
}

void Span::addRange (std::vector<int>::iterator start, std::vector<int>::iterator end) {
    int s = std::distance (start, end);
    if (s < 0)
        throw std::logic_error ("Invalid range");
    size_t capacity = _capacity - _span.size ();
    if (static_cast<size_t> (s) > capacity)
        throw std::logic_error ("Not enough capacity");
    _span.insert (_span.end (), start, end);
}
