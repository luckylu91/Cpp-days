#include "ShrubberyCreationForm.hpp"

std::string ShrubberyCreationForm::_nameFromTarget(std::string const & target)
{
	return target + " Shrubbery Creation Form";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form(_nameFromTarget(target), 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: Form(_nameFromTarget(other.target), 145, 137), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	// std::string fname(target + "_shrubbery");
	std::ofstream ofs(target + "_shrubbery");
	// ofs.exceptions(std::ofstream::badbit);
	// ofs.open(fname);
	for (std::size_t i = 0; i < target.length(); i++)
	{
		for (std::size_t j = 0; j < i; j++)
		{
			if (j == 0)
			{
				if (i < target.length() - 1)
					ofs << '|';
				else
					ofs << '`';
			}
			else
				ofs << '-';
		}
		ofs << target[i] << std::endl;
	}
}
