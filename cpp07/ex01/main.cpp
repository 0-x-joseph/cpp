#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T> void print(const T &element) {
  std::cout << element << " ";
}

void increment(int &n) { n++; }

int main() {
  int intArray[] = {1, 2, 3, 4, 5};
  size_t len = 5;

  iter(intArray, len, print<int>);
  std::cout << std::endl;

  iter(intArray, len, increment);

  iter(intArray, len, print<int>);
  std::cout << std::endl;

  std::string strArray[] = {"Hello", "1337", "Rabat", "Campus"};
  iter(strArray, 4, print<std::string>);
  std::cout << std::endl;

  return 0;
}
