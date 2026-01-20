#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
  Intern someRandomIntern;
  Bureaucrat boss("The Boss", 1);
  AForm *rrf;

  // Intern creates a form
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");

  if (rrf) {
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf;
  }

  // Testing a non-existent form
  AForm *unknown = someRandomIntern.makeForm("coffee request", "Intern");
  if (!unknown) {
    std::cout << "As expected, the intern failed to find the form."
              << std::endl;
  }

  return 0;
}
