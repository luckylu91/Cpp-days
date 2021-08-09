#include "ShrubberyCreationForm.hpp"

// Unreachable
ShrubberyCreationForm::ShrubberyCreationForm() {}

// Unreachable
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &) { return *this; };

std::string ShrubberyCreationForm::_nameFromTarget(std::string const & target)
{
	return target + " Shrubbery Creation Form";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form(_nameFromTarget(target), 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: Form(_nameFromTarget(other._target), 145, 137, other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::_execute(executor);

	std::ofstream ofs(this->_target + "_shrubbery");
	for (std::size_t i = 0; i < this->_target.length(); i++)
	{
		for (std::size_t j = 0; j < i; j++)
		{
			if (j == 0)
			{
				if (i < this->_target.length() - 1)
					ofs << '|';
				else
					ofs << '`';
			}
			else
				ofs << '-';
		}
		ofs << this->_target[i] << std::endl;
	}
}
