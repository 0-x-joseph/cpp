#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("Default"), _is_signed(false), _sign_grade(2), _exec_grade(1) {}

Form::Form(std::string name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false) {
  if (sign_grade < 1 || exec_grade < 1)
    throw Form::GradeTooHighException();
  if (sign_grade > 150 || exec_grade > 150)
    throw Form::GradeTooLowException();
  _sign_grade = sign_grade;
  _exec_grade = exec_grade;
}

Form::Form(const Form &other)
    : _name(other._name), _is_signed(other._is_signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    _is_signed = other._is_signed;
    _sign_grade = other._sign_grade;
    _exec_grade = other._exec_grade;
  }
  return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _is_signed; }

int Form::getSignGrade() const { return _sign_grade; }

int Form::getExecGrade() const { return _exec_grade; }

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _sign_grade) {
    throw Form::GradeTooLowException();
  }
  _is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
  out << "Form: " << f.getName()
      << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Grade to Sign: " << f.getSignGrade()
      << " | Grade to Execute: " << f.getExecGrade();
  return out;
}
