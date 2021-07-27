#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm & operator=(PresidentialPardonForm const &);
	std::string _target;
	static std::string _nameFromTarget(std::string const & target);
public:
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const &);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
};
