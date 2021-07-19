#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string target;
	static std::string _nameFromTarget(std::string const & target);
public:
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const & executor) const;
	// cannot be assigned (same as Form)
};
