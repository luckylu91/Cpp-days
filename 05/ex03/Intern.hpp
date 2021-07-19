#pragma once
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Intern
{
private:
	static Form * presidentialFormInit(std::string const & target);
	static Form * robotomyFormInit(std::string const & target);
	static Form * shrubberyFormInit(std::string const & target);
	typedef Form * (Intern::*t_formInit)(std::string const & target);
	static t_formInit formCtors[3];
	static std::string formNames[3];

public:

	class InvalidFormName : public std::exception
	{
	private:
		std::string _msg;
	public:
		InvalidFormName(std::string const & formName);
		virtual char const * what() const throw();
	};

	Intern();
	Intern(Intern const &);
	~Intern();
	Intern & operator=(Intern const &);
	Form * makeForm(std::string const & formName, std::string const & target) const;
};

