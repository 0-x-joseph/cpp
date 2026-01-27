#ifndef __ITER__
#define __ITER__

#include <cstddef>

template <typename T> void iter(T *addr, const size_t len, void (*fn)(T &)) {
  if (!addr || !fn)
    return;
  for (size_t i = 0; i < len; i++) {
    fn(addr[i]);
  }
}

template <typename T>
void iter(T *addr, const size_t len, void (*fn)(const T &)) {
  if (!addr || !fn)
    return;
  for (size_t i = 0; i < len; i++) {
    fn(addr[i]);
  }
}

#endif /* __ITER__ */
