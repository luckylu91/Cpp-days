#include "Intern.hpp"

Intern::t_formInit Intern::_formCreators[3] = {
	Intern::presidentialFormInit,
	Intern::robotomyFormInit,
	Intern::shrubberyFormInit
};

std::string Intern::_formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern() {}

Intern::Intern(Intern const &) {}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const &) { return *this; }

Form * Intern::presidentialFormInit(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

Form * Intern::robotomyFormInit(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

Form * Intern::shrubberyFormInit(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

Form * Intern::makeForm(std::string const & formName, std::string const & target) const
{
	static const std::string red("\033[0;31m");
	static const std::string green("\033[0;32m");
	static const std::string reset("\033[0m");

	for (size_t i = 0; i < 3; i++)
	{
		if (formName == this->_formNames[i])
		{
			std::cout << green << "Succes ! " << reset;
			std::cout << "Intern creates '" << formName << "'" << std::endl;
			return this->_formCreators[i](target);
		}
	}
	std::cerr << red << "Failure !" << reset << std::endl;
	std::cerr << "The form '" << formName << "' does not exist" << std::endl;
	return NULL;
}
