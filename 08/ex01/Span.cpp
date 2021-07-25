#include "Span.hpp"

std::ostream & operator<<(std::ostream & os, Span const & span)
{
	unsigned int i = 0;

	os << "Span<size=" << span.getSize() << ">(";
	if (span.getLength() > 10)
	{
		os << "..., ";
		i = span.getLength() - 10;
	}
	for (; i < span.getLength(); ++i)
	{
		try { os << span[i]; } catch (std::exception &) {}
		if (i < span.getLength() - 1)
			os << ", ";
	}
	os << ")";
	return os;
}

Span::Span() : _n(0), _len(0), _content(NULL) {}

Span::Span(unsigned int n) : _n(n), _len(0)
{
	this->_content = (n > 0) ? new int[n] : NULL;
}

void Span::_copy(Span const & other)
{
	if (this->_content)
		delete this->_content;
	this->_n = other._n;
	this->_len = other._len;
	this->_content = (other._n > 0) ? new int[other._n] : NULL;
}

Span::Span(Span const & other) { _copy(other); }

Span & Span::operator=(Span const & other)
{
	_copy(other);
	return *this;
}
Span::~Span()
{
	if (this->_content)
		delete this->_content;
}

unsigned int Span::getSize() const { return this->_n; }
unsigned int Span::getLength() const { return this->_len; }

int Span::operator[](unsigned int i) const throw(Span::OutOfBoundException)
{
	if (i > this->_len)
		throw Span::OutOfBoundException(*this, i);
	return this->_content[i];
}

void Span::addNumber(int i) throw(Span::ContainerIsFullException)
{
	if (this->_len == this->_n)
		throw Span::ContainerIsFullException(*this);
	this->_content[this->_len++] = i;
}

int Span::shortestSpan() const throw(Span::NotEnoughElementsException)
{
	unsigned int shortest;

	if (this->_len < 2)
		throw Span::NotEnoughElementsException();
	shortest = abs(this->_content[0] - this->_content[1]);
	for (unsigned int i = 0; i < this->_len - 1; i++)
	{
		std::min
		for (unsigned int j = i + 1; j < this->_len; j++)
		{
			sp = abs(this->_content[i] - this->_content[j]);
			if (sp < shortest)
				shortest = sp;
		}
	}
}

int Span::longestSpan() const throw(Span::NotEnoughElementsException)
{
	if (this->_len < 2)
		throw Span::NotEnoughElementsException();

}

Span::ContainerIsFullException::ContainerIsFullException(Span const & span)
{
	std::stringstream ss;
	ss << "This span is already full : " << span;
	this->_msg = ss.str();
};

char const * Span::ContainerIsFullException::what() const throw()
{
	return this->_msg.c_str();
}

Span::ContainerIsFullException::~ContainerIsFullException() throw() {}

Span::OutOfBoundException::OutOfBoundException(Span const & span, int i)
{
	std::stringstream ss;
	ss << "Index requested = " << i << ", size = " << span.getSize();
	this->_msg = ss.str();
}

char const * Span::OutOfBoundException::what() const throw()
{
	return this->_msg.c_str();
}

Span::OutOfBoundException::~OutOfBoundException() throw() {}

char const * Span::NotEnoughElementsException::what() const throw()
{
	return "This span isn't large enough to compute differences (length shoud be at least 2)";
}
