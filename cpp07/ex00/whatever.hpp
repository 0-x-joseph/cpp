#ifndef __WHATEVER__
#define __WHATEVER__

template <typename T> void swap(T &o1, T &o2) {
  T tmp;
  tmp = o1;
  o1 = o2;
  o2 = tmp;
}

template <typename T> const T min(const T &o1, const T &o2) {
  if (o1 >= o2)
    return o2;
  return o1;
}

template <typename T> const T max(const T &o1, const T &o2) {
  if (o2 >= o1)
    return o2;
  return o1;
}
#endif /* __WHATEVER__ */
