#pragma once
#include <string>
#include <exception>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
	Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const &);

public:
	struct GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw();
	};

	Bureaucrat(std::string name, int grade) throw(GradeTooLowException, GradeTooHighException);
	Bureaucrat(Bureaucrat const &);
	virtual ~Bureaucrat();
	std::string const & getName() const;
	int getGrade() const;
	Bureaucrat & incrementGrade();
	Bureaucrat & decrementGrade();
	void signForm(Form &);
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b);
