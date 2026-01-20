#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Robotmy Creation", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Robotmy Creation", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  this->isExecutable(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f) {
  out << "AForm: " << f.getName()
      << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Grade to Sign: " << f.getSignGrade()
      << " | Grade to Execute: " << f.getExecGrade();
  return out;
}
