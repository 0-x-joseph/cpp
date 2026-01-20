#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f);

#endif /* __SHRUBBERYCREATIONFORM__ */
