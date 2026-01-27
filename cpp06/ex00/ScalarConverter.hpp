#ifndef __SCALAR_CONVERTER__
#define __SCALAR_CONVERTER__

#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  static void print_char(double val);
  static void print_int(double val);
  static void print_float(double val);
  static void print_double(double val);

public:
  static void convert(const std::string &literal);
};

#endif /* __SCALER_CONVERTER__ */
