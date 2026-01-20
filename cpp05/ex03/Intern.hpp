#ifndef __INTERN__
#define __INTERN__

#include "AForm.hpp"
#include <string>

class Intern {
private:
  AForm *createShrubbery(std::string target);
  AForm *createRobotomy(std::string target);
  AForm *createPresidential(std::string target);

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);
};

#endif /* __INTERN__ */
