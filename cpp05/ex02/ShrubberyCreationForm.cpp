#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  this->isExecutable(executor);

  std::ofstream outfile((_target + "_shrubbery").c_str());
  if (!outfile.is_open())
    throw std::runtime_error("Could not open file");

  outfile << "               ,@@@@@@@," << std::endl;
  outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
  outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
  outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
  outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
  outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
  outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
  outfile << "       |o|        | |         | |" << std::endl;
  outfile << "       |.|        | |         | |" << std::endl;
  outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

  outfile.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f) {
  out << "AForm: " << f.getName()
      << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Grade to Sign: " << f.getSignGrade()
      << " | Grade to Execute: " << f.getExecGrade();
  return out;
}
