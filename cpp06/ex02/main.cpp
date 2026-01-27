#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void);
void identify(Base *ptr);
void identify(Base &ret);

int main() {
  (void)0;
  std::srand(std::time(0));

  for (int i = 0; i < 10; i++) {
    std::cout << "Test #" << i + 1 << std::endl;
    Base *instance = generate();

    std::cout << " Identify (pointer):   ";
    identify(instance);
    std::cout << " Identify (reference): ";
    identify(*instance);

    delete instance;

    std::cout
        << "==============================================================="
        << std::endl;
  }
  return (0);
}
