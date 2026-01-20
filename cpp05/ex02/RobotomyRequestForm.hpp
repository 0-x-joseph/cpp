#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif /* __ROBOTOMYREQUESTFORM__ */
