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
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

//Unreachable
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &) { return *this; }

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

Bureaucrat & Bureaucrat::operator++()
{
	if (this->_grade - 1 < 1)
		throw (GradeTooHighException());
	--this->_grade;
	return (*this);
}

Bureaucrat & Bureaucrat::operator--()
{
	if (this->_grade + 1 > 150)
		throw (GradeTooLowException());
	++this->_grade;
	return (*this);
}

