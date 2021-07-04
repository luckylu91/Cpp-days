#pragma once
#include <string>
#include <exception>

class Bureaucrat
{
private:
	std::string	name;
	int			grade;

	struct GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw();
	};
public:
	Bureaucrat(std::string name, int grade) throw(GradeTooLowException, GradeTooHighException);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const &);
	std::string const & getName() const;
	int getGrade() const;
	Bureaucrat & operator++();
	Bureaucrat & operator--();
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & b);
