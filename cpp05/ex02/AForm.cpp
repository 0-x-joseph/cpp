#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Default"), _is_signed(false), _sign_grade(2), _exec_grade(1) {}

AForm::AForm(std::string name, int sign_grade, int exec_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
  if (sign_grade < 1 || exec_grade < 1)
    throw AForm::GradeTooHighException();
  if (sign_grade > 150 || exec_grade > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _is_signed(other._is_signed),
      _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    _is_signed = other._is_signed;
  }
  return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _is_signed; }

int AForm::getSignGrade() const { return _sign_grade; }

int AForm::getExecGrade() const { return _exec_grade; }

void AForm::beSigned(const Bureaucrat &signer) {
  if (signer.getGrade() > _sign_grade) {
    throw AForm::GradeTooLowException();
  }
  _is_signed = true;
}

void AForm::isExecutable(const Bureaucrat &executor) const {
  if (!_is_signed)
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > _exec_grade)
    throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
  out << "AForm: " << f.getName()
      << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Grade to Sign: " << f.getSignGrade()
      << " | Grade to Execute: " << f.getExecGrade();
  return out;
}
