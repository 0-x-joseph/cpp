#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
    *this = other;
  }
  return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(std::string target) {
  return new ShrubberyCreationForm(target);
}
AForm *Intern::createRobotomy(std::string target) {
  return new RobotomyRequestForm(target);
}
AForm *Intern::createPresidential(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  const std::string names[] = {"shrubbery creation", "robotomy request",
                               "presidential pardon"};

  typedef AForm *(Intern::*FormCreator)(std::string);

  FormCreator functions[] = {&Intern::createShrubbery, &Intern::createRobotomy,
                             &Intern::createPresidential};

  for (int i = 0; i < 3; i++) {
    if (name == names[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return (this->*functions[i])(target);
    }
  }

  std::cout << "Error: " << name << " form name doesn't exist." << std::endl;
  return (NULL);
}
