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

Bureaucrat::Bureaucrat(std::string name, int grade)
	throw(GradeTooLowException, GradeTooHighException)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other)
{
	name = other.name;
	grade = other.grade;
	return *this;
}

std::string const & Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

Bureaucrat & Bureaucrat::operator++()
{
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	--grade;
	return (*this);
}

Bureaucrat & Bureaucrat::operator--()
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
	++grade;
	return (*this);
}

void Bureaucrat::executeForm(Form const & form) const
{
	static const std::string red("\033[0;31m");
	static const std::string green("\033[0;32m");
	static const std::string reset("\033[0m");

	std::cout << "Trying to make " << *this << " sign <" << form << ">" << std::endl;
	try
	{
		form.execute(*this);
		std::cout << green << "Succes ! " << reset;
		std::cout << name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << red << "Failure !" << reset << std::endl;
		std::cout << "The problem was : " << e.what() << std::endl;
	}
}
