#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <sstream>

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Too high a grade for a Bureaucrat";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Too low a grade for a Bureaucrat";
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b)
{
	os << "Bureaucrate <" << b.getName() << ">, grade " << b.getGrade();
	return os;
}

//Unreachable
Bureaucrat::Bureaucrat() {}

//Unreachable
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &) { return *this; }

Bureaucrat::Bureaucrat(std::string name, int grade)
	throw(GradeTooLowException, GradeTooHighException)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat & Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());
	--this->_grade;
	return (*this);
}

Bureaucrat & Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());
	++this->_grade;
	return (*this);
}

void Bureaucrat::signForm(Form & form)
{
	static const std::string red("\033[0;31m");
	static const std::string green("\033[0;32m");
	static const std::string reset("\033[0m");

	try
	{
		form.beSigned(*this);
		std::cout << green << "Success !" << reset;
		std::cout << " Bureaucrat " << this->_name;
		std::cout << " signs form '" << form.getName();
		std::cout << "'" << std::endl;
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << red << "Failure !" << reset;
		std::cerr << " Bureaucrat " << this->_name;
		std::cerr << " cannot sign form '" << form.getName() << "' : ";
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) const
{
	static const std::string red("\033[0;31m");
	static const std::string green("\033[0;32m");
	static const std::string reset("\033[0m");

	std::cout << "Trying to make " << *this << " execute <" << form << ">" << std::endl;
	try
	{
		form.execute(*this);
		std::cout << green << "Succes ! " << reset;
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << red << "Failure !" << reset << std::endl;
		std::cerr << "The problem was : " << e.what() << std::endl;
	}
}
