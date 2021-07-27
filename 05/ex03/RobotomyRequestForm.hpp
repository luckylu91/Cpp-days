#pragma once
#include "Form.hpp"
#include <string>
#include <iostream>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm & operator=(RobotomyRequestForm const &);
	std::string _target;
	static std::string _nameFromTarget(std::string const & target);
	static bool _robotomyAleas;
public:
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const &);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
};
