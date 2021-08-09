#include "RobotomyRequestForm.hpp"

// Unreachable
RobotomyRequestForm::RobotomyRequestForm() {}

// Unreachable
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &) { return *this; };

std::string RobotomyRequestForm::_nameFromTarget(std::string const & target)
{
	return "Robotomy Request Form of " + target;
}

bool RobotomyRequestForm::_robotomyAleas = true;

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form(_nameFromTarget(target), 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: Form(_nameFromTarget(other._target), 72, 45, other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::_execute(executor);
	std::cout << "The robotomy of " << this->_target << " was ";
	std::cout << (RobotomyRequestForm::_robotomyAleas ? "successful !" : "a failure...") << std::endl;
	RobotomyRequestForm::_robotomyAleas = !RobotomyRequestForm::_robotomyAleas;
}
