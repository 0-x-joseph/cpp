#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();

  void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f);

#endif /* __PRESIDENTIALPARDONFORM__ */
