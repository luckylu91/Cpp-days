#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public Form
{
private:
	std::string target;
	static std::string _nameFromTarget(std::string const & target);
public:
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const &);
	~PresidentialPardonForm();
	virtual void execute(Bureaucrat const & executor) const;
	// cannot be assigned (same as Form)
};
