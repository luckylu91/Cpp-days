#include "PresidentialPardonForm.hpp"

// Unreachable
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &) { return *this; };

std::string PresidentialPardonForm::_nameFromTarget(std::string const & target)
{
	return "Presidential Pardon Form of " + target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form(_nameFromTarget(target), 145, 137), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
	: Form(_nameFromTarget(other._target), 145, 137), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
