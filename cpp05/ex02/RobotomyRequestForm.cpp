#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotmy Creation", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotmy Creation", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  this->isExecutable(executor);

  std::cout << "* NOISEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE *"
            << std::endl;

  if (std::rand() % 2 == 0)
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "Robotmy on " << _target << "failed." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &f) {
  out << "AForm: " << f.getName()
      << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Grade to Sign: " << f.getSignGrade()
      << " | Grade to Execute: " << f.getExecGrade();
  return out;
}
