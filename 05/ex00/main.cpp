#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

static void createBureaucrat(std::string name, int grade) throw ()
{
	static const std::string red("\033[0;31m");
	static const std::string green("\033[0;32m");
	static const std::string reset("\033[0m");

	std::cout << "Trying to create a bureaucrate named " << name << " and grade " << grade << std::endl;
	try
	{
		Bureaucrat b(name, grade);
		std::cout << green << "Success !" << reset << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << red << "Failure !" << reset << std::endl;
		std::cout << "The problem was : " << e.what() << std::endl;
	}
}

int main()
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
			b.incrementGrade();
			std::cout << b << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << "Stop this nonsense : " << e.what() << std::endl;
	}
}
