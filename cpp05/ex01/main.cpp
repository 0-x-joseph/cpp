#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Form high("Top Secret", 0, 1);
  } catch (std::exception &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }

  try {
    Form low("Trash", 151, 150);
  } catch (std::exception &e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat boss("The Boss", 1);
    Form contract("Standard Contract", 50, 25);

    std::cout << boss << std::endl;
    std::cout << contract << std::endl;

    boss.signForm(contract);
    std::cout << contract << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat intern("Intern", 140);
    Form difficult("Hard Form", 10, 5);

    std::cout << intern << std::endl;
    std::cout << difficult << std::endl;

    intern.signForm(difficult);
    std::cout << difficult << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Main caught unexpected exception: " << e.what() << std::endl;
  }

  return 0;
}
