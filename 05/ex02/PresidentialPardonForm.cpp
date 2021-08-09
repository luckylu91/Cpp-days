#include "PresidentialPardonForm.hpp"

// Unreachable
PresidentialPardonForm::PresidentialPardonForm() {}

// Unreachable
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &) { return *this; };

std::string PresidentialPardonForm::_nameFromTarget(std::string const & target)
{
	return "Presidential Pardon Form of " + target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form(_nameFromTarget(target), 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
	: Form(_nameFromTarget(other._target), 25, 5, other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::_execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
