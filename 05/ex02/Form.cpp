#include "Form.hpp"

// Uneachable
Form & Form::operator=(Form const &) { return *this; };

std::string	Form::_exceptionMessage(std::string fieldName, bool low) const
{
	std::stringstream ss;

	ss << "The given grade for the field '" << fieldName << "' is too ";
	ss << (low ? "low" : "high");
	return ss.str();
}

std::string	Form::_exceptionMessage(Bureaucrat const & b, bool actionIsSign) const
{
	std::stringstream ss;
	std::string actionStr(actionIsSign ? "sign" : "execute");
	int gradeRequired = actionIsSign ? _requireSign : _requireExecute;

	ss << b.getName();
	ss << " has a grade too low to " << actionStr << " this form ";
	ss << "(bureaucrat's grade : " << b.getGrade();
	ss << ", form requires: " << gradeRequired << ")";
	return ss.str();
}

Form::GradeTooHighException::GradeTooHighException(std::string message): _msg(message) {}

const char * Form::GradeTooHighException::what() const throw() { return _msg.c_str(); }

Form::GradeTooLowException::GradeTooLowException(std::string message): _msg(message) {}

const char * Form::GradeTooLowException::what() const throw() { return _msg.c_str(); }

const char * Form::NotSignedException::what() const throw() { return "The form is not signed"; }

Form::GradeTooHighException::~GradeTooHighException() throw() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::Form(std::string name, int rSign, int rExecute) : _isSigned(false),
	_name(name), _requireSign(rSign), _requireExecute(rExecute)
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

Form::Form(Form const & other) : _isSigned(other._isSigned), _name(other._name),
	_requireSign(other._requireSign), _requireExecute(other._requireExecute) {}

Form::~Form() {}

std::string const & Form::getName() const
{
	return this->_name;
}

int Form::getRequireSign() const
{
	return this->_requireSign;
}

int Form::getRequireExecute() const
{
	return this->_requireExecute;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
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
	if (b.getGrade() <= this->_requireSign)
	{
		this->_isSigned = true;
	}
	else
		throw Form::GradeTooLowException(_exceptionMessage(b, true));
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_requireExecute)
		throw Form::GradeTooLowException(_exceptionMessage(executor, false));
	if (!this->_isSigned)
		throw Form::NotSignedException();
}
