#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(NULL));

  std::cout << "Creating Bureaucrats" << std::endl;
  Bureaucrat boss("The Boss", 1);
  Bureaucrat minion("The Minion", 140);
  Bureaucrat middleManager("The Manager", 40);

  std::cout << "\nCreating Forms" << std::endl;
  ShrubberyCreationForm shrub("home");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << "\nTesting Shrubbery (Sign 145, Exec 137)" << std::endl;
  minion.signForm(shrub);
  minion.executeForm(shrub);
  boss.executeForm(shrub);

  std::cout << "\nTesting Robotomy (Sign 72, Exec 45)" << std::endl;
  boss.signForm(robot);
  middleManager.executeForm(robot);
  boss.executeForm(robot);
  boss.executeForm(robot);

  std::cout << "\nTesting Presidential Pardon (Sign 25, Exec 5)" << std::endl;
  middleManager.signForm(pardon);
  boss.signForm(pardon);
  boss.executeForm(pardon);

  std::cout << "\nTesting Unsigned Form Error" << std::endl;
  PresidentialPardonForm unsignedForm("Criminal");
  boss.executeForm(unsignedForm);

  return 0;
}
