#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <iostream>

class Form
{
private:
	bool				isSigned;
	std::string const	name;
	int const			requireSign;
	int const			requireExecute;

	std::string	_exceptionMessage(std::string fieldName, bool low) const;
	std::string	_exceptionMessage(Bureaucrat const & b, bool actionIsSign) const;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(std::string message);
		virtual const char * what() const throw();
	protected:
		std::string _msg;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(std::string message);
		virtual const char * what() const throw();
	protected:
		std::string _msg;
	};

	struct NotSignedException : public std::exception
	{
		virtual const char * what() const throw();
	};

	Form(std::string name, int rSign, int rExecute);
	Form(Form const &);
	~Form();
	// cant have assignation operator because some members are const
	std::string const & getName() const;
	int getRequireSign() const;
	int getRequireExecute() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat const & b) throw(Form::GradeTooLowException);
	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & os, Form const & f);
