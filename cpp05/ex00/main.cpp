#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat bob("Bob", 10);
    std::cout << bob << std::endl;

    Bureaucrat sam("Sam", 0);
    std::cout << sam << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
