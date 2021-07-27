#include "RobotomyRequestForm.hpp"

// Unreachable
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &) { return *this; };

std::string RobotomyRequestForm::_nameFromTarget(std::string const & target)
{
	return "Robotomy Request Form of " + target;
}

bool RobotomyRequestForm::_robotomyAleas = true;

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form(_nameFromTarget(target), 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: Form(_nameFromTarget(other._target), 145, 137), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "The robotomy of " << _target << " was ";
	std::cout << (_robotomyAleas ? "successful !" : "a failure...") << std::endl;
	_robotomyAleas = !_robotomyAleas;
}
