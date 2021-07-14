#pragma once
#include <string>
#include <exception>
#include <sstream>
#include "Form.hpp"

class Bureaucrat
{
private:
	std::string	name;
	int			grade;

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
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const &);
	std::string const & getName() const;
	int getGrade() const;
	Bureaucrat & operator++();
	Bureaucrat & operator--();
	void executeForm(Form const & form) const;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b);
