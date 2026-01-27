#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  int r = std::rand() % 3;
  if (r == 0)
    return new A();
  if (r == 1)
    return new B();
  return new C();
}

void identify(Base *ptr) {
  if (dynamic_cast<A *>(ptr))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(ptr))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(ptr))
    std::cout << "C" << std::endl;
}

void identify(Base &ref) {
  try {
    (void)dynamic_cast<A &>(ref);
    std::cout << "A" << std::endl;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<B &>(ref);
    std::cout << "B" << std::endl;
  } catch (...) {
  }
  try {
    (void)dynamic_cast<C &>(ref);
    std::cout << "C" << std::endl;
  } catch (...) {
  }
}
