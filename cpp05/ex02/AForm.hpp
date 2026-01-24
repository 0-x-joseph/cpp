#ifndef __AFORM__
#define __AFORM__

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _is_signed;
  const int _sign_grade;
  const int _exec_grade;

public:
  AForm();
  AForm(const std::string name, int sign_grade, int exec_grade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  ~AForm();

  std::string getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat &signer);
  virtual void execute(const Bureaucrat &executor) const = 0;
  void isExecutable(const Bureaucrat &executor) const;

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif /* __AFORM__ */
