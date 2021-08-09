#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const &);
	static std::string _nameFromTarget(std::string const & target);
public:
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	virtual ~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
};
