#include "easyfind.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  try {
    std::vector<int>::iterator it = easyfind(v, 20);
    std::cout << "Found: " << *it << std::endl;

    easyfind(v, 42);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
