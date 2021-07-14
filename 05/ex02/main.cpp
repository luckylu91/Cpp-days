#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

static void createBureaucrat(std::string name, int grade) throw ()
{
	std::cout << "Trying to create a bureaucrate named " << name << " and grade " << grade << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Success !" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Failure !" << std::endl;
		std::cout << "The problem was : " << e.what() << std::endl;
	}
}

static void createForm(std::string name, int rSign, int rExecute) throw ()
{
	std::cout << "Trying to create a form named " << name;
	std::cout << ", requiresign = " << rSign;
	std::cout << ", requireExecute = " << rExecute << std::endl;
	try
	{
		Form f(name, rSign, rExecute);
		std::cout << "Success ! " << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Failure !" << std::endl;
		std::cout << "The problem was : " << e.what() << std::endl;
	}
}

static void trySign(Bureaucrat const & b, Form & f)
{
	std::cout << "Trying to make " << b << " sign <" << f << ">" << std::endl;
	try
	{
		f.beSigned(b);
		std::cout << "Success ! Bureaucrat " << b.getName();
		std::cout << " managed to sign form '" << f.getName();
		std::cout << "'" << std::endl;
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cout << "Failure !" << std::endl;
		std::cout << "The problem was : " << e.what() << std::endl;
	}
}

int main()
{
	{
		createBureaucrat("b1", 0);
		createBureaucrat("b2", 155);
		createBureaucrat("b3", 75);

		Bureaucrat b("Hermes Conrad", 5);

		try
		{
			std::cout << b << " is gaining grades too fast !" << std::endl;
			while (1)
			{
				std::cout << "Promoting " << b << "..." << std::endl;
				++b;
				std::cout << b << std::endl;
			}
		}
		catch (Bureaucrat::GradeTooHighException & e)
		{
			std::cout << "Stop this nonsense : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		createForm("fRequireLow", 0, 20);
		createForm("fRequireHigh", 152, 20);
		createForm("fExecuteLow", 20, -1);
		createForm("fExecuteHigh", 20, 12000);
		createForm("fOK", 10, 10);

		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Billy", 150);
		Form teslaContract("Tesla Contract", 10, 5);
		Form crosswords("WC's crosswords", 150, 150);

		trySign(intern, teslaContract);
		trySign(boss, teslaContract);
		trySign(intern, crosswords);
	}
	std::cout << std::endl;
	{
		ShrubberyCreationForm	shForm("eco-friendly-polyurethan");
		RobotomyRequestForm		robForm("Bender Rodriguez");
		PresidentialPardonForm	presForm("Jeff Bezos");

		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Billy", 150);

		intern.executeForm(shForm);
		intern.executeForm(presForm);
		intern.executeForm(robForm);
		std::cout << std::endl;

		boss.executeForm(shForm);
		boss.executeForm(presForm);
		boss.executeForm(robForm);
		std::cout << std::endl;

		shForm.beSigned(boss);
		presForm.beSigned(boss);
		robForm.beSigned(boss);
		boss.executeForm(shForm);
		boss.executeForm(presForm);
		boss.executeForm(robForm);
	}
}
