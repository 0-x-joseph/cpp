#ifndef __ARRAY__
#define __ARRAY__

#include <cstdlib>
#include <exception>

template <typename T> class Array {
private:
  T *_arr;
  unsigned int _size;

public:
  Array() : _arr(NULL), _size(0) {}

  Array(unsigned int n) : _size(n) {
    if (_size == 0)
      _arr = NULL;
    else
      _arr = new T[_size]();
  }

  Array(const Array &src) : _arr(NULL), _size(0) { *this = src; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      if (_arr)
        delete[] _arr;
      _size = other._size;
      if (_size == 0)
        _arr = NULL;
      else {
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
          _arr[i] = other._arr[i];
      }
    }
    return *this;
  }

  ~Array() {
    if (_arr)
      delete[] _arr;
  }

  unsigned int size() const { return _size; }
  T &operator[](unsigned int index) {
    if (!_arr || index >= _size)
      throw OutOfBoundsException();
    return _arr[index];
  }

  const T &operator[](unsigned int index) const {
    if (_arr == NULL || index >= _size)
      throw OutOfBoundsException();
    return _arr[index];
  }

  class OutOfBoundsException : public std::exception {
    virtual const char *what() const throw() {
      return "OutOFBoundsException: index out of bound";
    }
  };
};

#endif /* __ARRAY__ */
