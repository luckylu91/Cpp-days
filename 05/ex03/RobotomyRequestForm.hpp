#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>

class RobotomyRequestForm : public Form
{
private:
	std::string target;
	static std::string _nameFromTarget(std::string const & target);
	static bool robotomyAleas;
public:
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const &);
	~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
	// cannot be assigned (same as Form)
};
