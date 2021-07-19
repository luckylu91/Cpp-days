#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>

void printUsage()
{
	std::cerr << "Usage : ./convert arg" << std::endl;
	std::cerr << "\targ: string representation of a litteral" << std::endl;
}

class Converter
{
private:
	bool		intitialized;
	typedef enum e_type_from {CHAR, INT, FLOAT, DOUBLE, UNKNOWN} t_type_from;
	char 		c;
	int 		i;
	float 		f;
	double 		d;
	t_type_from	t;
	bool		charConvertible;
	bool		intConvertible;
	bool		floatConvertible;
	bool		doubleConvertible;
	static char const *consumeMinus(char const *s);
	static char const *consumeInt(char const *s);
	static char const *consumeDouble(char const *s);
	bool fromInt(std::string const & str);
	bool fromFloat(std::string const & str);
	bool fromDouble(std::string const & str);
	bool fromChar(std::string const & str);
public:
	Converter();
	Converter(Converter const &);
	//Converter & operator=(Converter const &);
	~Converter();
	Converter & fromString(std::string const & str);
	void show();
};

Converter::Converter() : intitialized(false) {}

Converter::~Converter() {}

Converter::Converter(Converter const & other) : intitialized(other.intitialized),
	c(other.c), i(other.i), f(other.f), d(other.d), t(other.t) {}

// Converter & Converter::operator=(Converter const & other) {}

Converter & Converter::fromString(std::string const & str)
{
	if (!(fromChar(str) || fromInt(str) || fromFloat(str) || fromDouble(str)))
		this->t = UNKNOWN;
	return *this;
}

char const *Converter::consumeMinus(char const *s)
{
	if (*s == '-')
		s++;
	return s;
}

char const *Converter::consumeInt(char const *s)
{
	while (*s && std::isdigit(*s))
		s++;
	return s;
}

char const *Converter::consumeDouble(char const *s)
{
	s = consumeMinus(s);
	s = consumeInt(s);
	if (*s == '.')
		s++;
	s = consumeInt(s);
	return s;
}

bool Converter::fromInt(std::string const & str)
{
	char const *s = str.c_str();
	s = consumeMinus(s);
	s = consumeInt(s);
	if (*s == '\0')
	{
		this->t = INT;
		std::stringstream ss(str);
		ss >> this->i;
		this->c = (char) this->i;
		this->f = (float) this->i;
		this->d = (double) this->i;
		return true;
	}
	return false;
}

bool Converter::fromFloat(std::string const & str)
{
	char const *s = str.c_str();
	static char const *constants[3] = {
		"-inff", "+inff", "nanf"
	};

	for (int i = 0; i < 3; i++)
	{
		if (std::strcmp(s, constants[i]) == 0)
			return true;
	}
	s = consumeDouble(s);
	if (std::strcmp(s, "f") == 0)
	{
		this->t = FLOAT;
		std::stringstream ss(str);
		ss >> this->f;
		this->c = (char) this->f;
		this->i = (int) this->f;
		this->d = (double) this->f;
		return true;
	}
	return false;
}

bool Converter::fromDouble(std::string const & str)
{
	char const *s = str.c_str();
	static char const *constants[3] = {
		"-inf", "+inf", "nan"
	};
	static double const values[3] = {}

	for (int i = 0; i < 3; i++)
	{
		if (std::strcmp(s, constants[i]) == 0)
			return true;
	}
	s = consumeDouble(s);
	if (*s == '\0')
	{
		this->t = DOUBLE;
		std::stringstream ss(str);
		ss >> this->d;
		this->c = (char) this->d;
		this->i = (int) this->d;
		this->f = (float) this->d;
		return true;
	}
	return false;
}

bool Converter::fromChar(std::string const & str)
{
	if ((str.length() == 3) && (str[0] == '\'') && (str[2] == '\''))
	{
		this->t = CHAR;
		this->c = str[1];
		this->i = (int) this->c;
		this->f = (float) this->c;
		this->d = (double) this->c;
		return true;
	}
	return false;
}

void Converter::show()
{
	if (this->t == UNKNOWN)
		std::cout << "Given input is not of any acceped types" << std::endl;
	std::cout << "char: ";
	if (std::isprint(this->c))
		std::cout << this->c;
	else
		std::cout << "Non displayable";

}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printUsage();
		return 1;
	}
	Converter conv;
	conv.fromString(argv[1]);
	return 0;
}

