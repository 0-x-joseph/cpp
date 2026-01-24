#ifndef __FORM__
#define __FORM__

#include <string>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _is_signed;
  const int _sign_grade;
  const int _exec_grade;

public:
  Form();
  Form(const std::string name, int sign_grade, int exec_grade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  std::string getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat &b);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif /* __FORM__ */
