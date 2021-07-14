#include "RobotomyRequestForm.hpp"

std::string RobotomyRequestForm::_nameFromTarget(std::string const & target)
{
	return "Robotomy Request Form of " + target;
}

bool RobotomyRequestForm::robotomyAleas = true;

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form(_nameFromTarget(target), 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: Form(_nameFromTarget(other.target), 145, 137), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "The robotomy of " << target << " was ";
	std::cout << (robotomyAleas ? "successful !" : "a failure...") << std::endl;
	robotomyAleas = !robotomyAleas;
}
