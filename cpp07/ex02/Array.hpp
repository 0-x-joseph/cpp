#ifndef __ARRAY__
#define __ARRAY__

template <typename T> class Array {
private:
  T *arr;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &src);
  Array &operator=(const Array &other);
  ~Array();
};

#endif /* __ARRAY__ */
