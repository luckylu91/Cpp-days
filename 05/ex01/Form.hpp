#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Form
{
private:
	bool				isSigned;
	std::string const	name;
	int const			requireSign;
	int const			requireExecute;

	struct GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw();
	};

public:
	Form(std::string name, int rSign, int rExecute);
	Form(Form const &);
	~Form();
	Form & operator=(Form const &);
	std::string const & getName() const;
	int getRequireSign() const;
	int getRequireExecute() const;
	void beSigned(Bureaucrat & b);
};

Form::Form(std::string name, int rSign, int rExecute)
	: name(name), isSigned(false)
{
	if (rSign < 1)
		throw (GradeTooHighException());
	if (rSign > 150)
		throw (GradeTooLowException());
	if (rExecute < 1)
		throw (GradeTooHighException());
	if (rExecute > 150)
		throw (GradeTooLowException());
	requireSign = rSign;
	requireExecute = rExecute;
}

Form::Form(Form const & other) : name(other.name), isSigned(other.isSigned),
	requireSign(other.requireSign), requireExecute(other.requireExecute) {}

Form::~Form() {}

Form & Form::operator=(Form const & other)
{
	name = other.name;
	requireSign = other.requireSign;
	requireExecute = other.requireExecute;
	return *this;
}

std::string const & Form::getName() const
{
	return name;
}

int Form::getRequireSign() const
{
	return requireSign;
}

int Form::getRequireExecute() const
{
	return requireExecute;
}

std::ostream & operator<< (std::ostream & os, Form & form)
{
	std::cout << "Form '" << name << "' (required sign : " << form.getRequireSign();
	std::cout << ", required execute : " << form.getRequireExecute() << ")" << std::endl;
}

void Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() <= requireSign)
		isSigned = true;
	else
		.....
}
