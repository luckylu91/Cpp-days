#pragma once
#include <cstddef>
#include <exception>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

class Span
{
private:
	unsigned int	_n;
	unsigned int	_len;
	int				*_content;
	Span();
	void _copy(Span const & other);


public:
	class ContainerIsFullException : public std::exception
	{
		std::string		_msg;
	public:
		~ContainerIsFullException() throw();
		ContainerIsFullException(Span const &);
		virtual const char * what() const throw();
	};

	class OutOfBoundException : public std::exception
	{
		std::string		_msg;
	public:
		~OutOfBoundException() throw();
		OutOfBoundException(Span const &, int);
		virtual const char * what() const throw();
	};

	struct NotEnoughElementsException : public std::exception
	{
		virtual const char * what() const throw();
	};

	Span(unsigned int n);
	Span(Span const &);
	~Span();
	Span & operator=(Span const &);
	unsigned int getSize() const;
	unsigned int getLength() const;
	int operator[](unsigned int i) const throw(Span::OutOfBoundException);
	void addNumber(int i) throw(Span::ContainerIsFullException);
	template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) throw(Span::ContainerIsFullException);
	int shortestSpan() const throw(Span::NotEnoughElementsException);
	int longestSpan() const throw(Span::NotEnoughElementsException);
};

std::ostream & operator<<(std::ostream & os, Span const & span);

template <typename InputIterator>
	void Span::addNumbers(InputIterator begin, InputIterator end) throw(Span::ContainerIsFullException)
{
	for (InputIterator it = begin; it != end; ++it)
	{
		if (this->_len == this->_n)
			throw Span::ContainerIsFullException(*this);
		this->_content[this->_len++] = *it;
	}
}
