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
	typedef Form * (*t_formInit)(std::string const & target);
	static t_formInit _formCreators[3];
	static std::string _formNames[3];

public:
	Intern();
	Intern(Intern const &);
	virtual ~Intern();
	Intern & operator=(Intern const &);
	Form * makeForm(std::string const & formName, std::string const & target) const;
};

