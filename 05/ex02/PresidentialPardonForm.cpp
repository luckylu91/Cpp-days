#include "PresidentialPardonForm.hpp"

std::string PresidentialPardonForm::_nameFromTarget(std::string const & target)
{
	return "Presidential Pardon Form of " + target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form(_nameFromTarget(target), 145, 137), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
	: Form(_nameFromTarget(other.target), 145, 137), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
