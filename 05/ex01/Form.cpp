#include "Form.hpp"

std::string	Form::_exceptionMessage(std::string fieldName, bool low) const
{
	std::stringstream ss;

	ss << "The given grade for the field '" << fieldName << "' is too ";
	ss << (low ? "low" : "high");
	return ss.str();
}

std::string	Form::_exceptionMessage(Bureaucrat const & b) const
{
	std::stringstream ss;

	ss << "The bureaucrat named " << b.getName();
	ss << " has a grade too low to sign this form ";
	ss << "(bureaucrat'grade : " << b.getGrade();
	ss << ", form requires: " << requireSign << ")";
	return ss.str();
}

Form::GradeTooHighException::GradeTooHighException(std::string message): _msg(message) {}

const char * Form::GradeTooHighException::what() const throw() { return _msg.c_str(); }

Form::GradeTooLowException::GradeTooLowException(std::string message): _msg(message) {}

const char * Form::GradeTooLowException::what() const throw() { return _msg.c_str(); }


Form::Form(std::string name, int rSign, int rExecute) : isSigned(false),
	name(name), requireSign(rSign), requireExecute(rExecute)
{
	if (rSign < 1)
		throw (GradeTooHighException(_exceptionMessage("requireSign", false)));
	if (rSign > 150)
		throw (GradeTooLowException(_exceptionMessage("requireSign", true)));
	if (rExecute < 1)
		throw (GradeTooHighException(_exceptionMessage("requireExecute", false)));
	if (rExecute > 150)
		throw (GradeTooLowException(_exceptionMessage("requireExecute", true)));
}

Form::Form(Form const & other) : isSigned(other.isSigned), name(other.name),
	requireSign(other.requireSign), requireExecute(other.requireExecute) {}

Form::~Form() {}

std::string const & Form::getName() const
{
	return name;
}

int Form::getRequireSign() const
{
	return requireSign;
}

int Form::getRequireExecute() const
{
	return requireExecute;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

std::ostream & operator<< (std::ostream & os, Form const & form)
{
	os << "Form '" << form.getName();
	os << "' (required sign : " << form.getRequireSign();
	os << ", required execute : " << form.getRequireExecute();
	os << ") : ";
	os << (form.getIsSigned() ? "signed" : "not signed yet");
	return os;
}

void Form::beSigned(Bureaucrat const & b) throw(Form::GradeTooLowException)
{
	if (b.getGrade() <= requireSign)
	{
		isSigned = true;
	}
	else
		throw Form::GradeTooLowException(_exceptionMessage(b));
}
