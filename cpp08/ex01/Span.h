#ifndef __SPAN__
#define __SPAN__

#include <vector>
class Span {
private:
  std::vector<int> _span;
  unsigned int _capacity;

public:
  Span();
  Span(unsigned int n);
  Span(const Span &src);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int num);
  int shortestSpan() const;
  int longestSpan() const;
  void addRange(std::vector<int>::iterator start,
                std::vector<int>::iterator end);
};

#endif /* __SPAN__ */
