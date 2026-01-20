#ifndef __AFORM__
#define __AFORM__

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _is_signed;
  int _sign_grade;
  int _exec_grade;

public:
  AForm();
  AForm(const std::string name, int sign_grade, int exec_grade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  std::string getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat &signer);
  virtual void execute(const Bureaucrat &executor) const = 0;
  void isExecutable(const Bureaucrat &executor) const;

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Form not signed!"; }
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif /* __AFORM__ */
