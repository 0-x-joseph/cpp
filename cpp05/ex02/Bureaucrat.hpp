#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  void signForm(AForm &f);

  void executeForm(const AForm &f);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif /* __BUREAUCRAT__ */
