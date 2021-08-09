#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	bool				_isSigned;
	std::string const	_name;
	int const			_requireSign;
	int const			_requireExecute;

	std::string	_exceptionMessage(std::string fieldName, bool low) const;
	std::string	_exceptionMessage(Bureaucrat const & b, bool actionIsSign) const;

protected:
	std::string const	_target;

	Form();
	Form & operator=(Form const &);
	void _execute(Bureaucrat const & executor) const;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(std::string message);
		virtual const char * what() const throw();
	protected:
		std::string _msg;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(std::string message);
		virtual const char * what() const throw();
	protected:
		std::string _msg;
	};

	struct NotSignedException : public std::exception
	{
		virtual const char * what() const throw();
	};

	Form(std::string name, int rSign, int rExecute, std::string target);
	Form(Form const &);
	virtual ~Form();
	std::string const & getName() const;
	int getRequireSign() const;
	int getRequireExecute() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat const & b) throw(Form::GradeTooLowException);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & os, Form const & f);
