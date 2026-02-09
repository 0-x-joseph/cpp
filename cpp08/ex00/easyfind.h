#ifndef __EASYFIND__
#define __EASYFIND__

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &collection, int member) {
  typename T::iterator it =
      std::find(collection.begin(), collection.end(), member);
  if (it == collection.end()) {
    throw std::out_of_range("Element not found in collection");
  }
  return it;
}

#endif /* __EASYFIND__ */
