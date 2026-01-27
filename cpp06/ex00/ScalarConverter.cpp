#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::print_char(double val) {
  std::cout << "char: ";

  if (std::isnan(val) || val < 0 || val > 127) {
    std::cout << "Impossible" << std::endl;
  } else if (!std::isprint(static_cast<int>(val))) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
  }
}

void ScalarConverter::print_int(double val) {
  std::cout << "int: ";

  if (std::isnan(val) || std::isinf(val) || val < INT_MIN || val > INT_MAX) {
    std::cout << "Impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(val) << std::endl;
  }
}

void ScalarConverter::print_float(double val) {
  std::cout << "float: ";

  if (std::isnan(val)) {
    std::cout << "nanf" << std::endl;
  } else if (std::isinf(val)) {
    std::cout << (val < 0 ? "-inff" : "+inff") << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val)
              << "f" << std::endl;
  }
}

void ScalarConverter::print_double(double val) {
  std::cout << "double: ";

  if (std::isnan(val)) {
    std::cout << "nan" << std::endl;
  } else if (std::isinf(val)) {
    std::cout << (val < 0 ? "-inf" : "+inf") << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << val << std::endl;
  }
}

void ScalarConverter::convert(const std::string &literal) {

  double val;
  char *end;

  if (literal.length() == 1 && !std::isdigit(literal[0])) {
    val = static_cast<double>(literal[0]);
  } else {
    val = std::strtod(literal.c_str(), &end);
    if (*end != 0) {
      if (!(*end == 'f' && end[1] == '\0')) {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
      }
    }
  }
  print_char(val);
  print_int(val);
  print_float(val);
  print_double(val);
}
