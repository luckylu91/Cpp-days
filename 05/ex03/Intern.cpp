#include "Intern.hpp"

Intern::InvalidFormName::InvalidFormName(std::string const & formName)
{
	std::stringstream ss;
	ss << "The form '" << formName << "' does not exist";
	_msg = ss.str();
}

char const * Intern::InvalidFormName::what() const throw()
{
	return _msg.c_str();
}

Intern::t_formInit Intern::formCtors[3] = {
	Intern::presidentialFormInit,
	Intern::robotomyFormInit,
	Intern::shrubberyFormInit
};

std::string Intern::formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

Intern::Intern() {}

Intern::Intern(Intern const & other) {}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & other) { return *this; }

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
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates '" << formName << "'" << std::endl;
			return formCtors[i](target);
		}
	}
	throw Intern::InvalidFormName(formName);
	return NULL;
}
