#include "Converter.hpp"

Converter::Converter() : intitialized(false) {}

Converter::~Converter() {}

Converter::Converter(Converter const & other) : intitialized(other.intitialized), intConvertible(other.intConvertible),
	c(other.c), i(other.i), f(other.f), d(other.d), t(other.t) {}

Converter & Converter::operator=(Converter const & other)
{
	intitialized = other.intitialized;
	intConvertible = other.intConvertible;
	c = other.c;
	i = other.i;
	f = other.f;
	d = other.d;
	t = other.t;
	return *this;
}

Converter & Converter::fromString(std::string const & str)
{
	this->intConvertible = true;
	if (!(fromChar(str) || fromInt(str) || fromFloat(str) || fromDouble(str)))
		this->t = UNKNOWN;
	this->intitialized = true;
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
		this->c = static_cast<char>(this->i);
		this->f = static_cast<float>(this->i);
		this->d = static_cast<double>(this->i);
		return true;
	}
	return false;
}

bool Converter::fromFloat(std::string const & str)
{
	static char const *constants[3] = {
		"-inff", "+inff", "nanf"
	};
	static double const values[3] = {
		std::numeric_limits<float>::min(),
		std::numeric_limits<float>::max(),
		nanf("")
	};
	bool isFloat = false;

	for (int i = 0; i < 3; i++)
	{
		if (str == constants[i])
		{
			this->f = values[i];
			isFloat = true;
			intConvertible = false;
		}
	}
	if (!isFloat)
	{
		char const *s = str.c_str();
		s = consumeDouble(s);
		if (std::strcmp(s, "f") == 0)
		{
			isFloat = true;
			std::stringstream ss(str.substr(0, str.length() - 1));
			ss >> this->f;
		}
	}
	if (isFloat)
	{
		this->t = FLOAT;
		this->c = static_cast<char>(this->f);
		this->i = static_cast<int>(this->f);
		this->d = static_cast<double>(this->f);
	}
	return isFloat;
}

bool Converter::fromDouble(std::string const & str)
{
	static char const *constants[3] = {
		"-inf", "+inf", "nan"
	};
	static double const values[3] = {
		std::numeric_limits<double>::min(),
		std::numeric_limits<double>::max(),
		nan("")
	};
	bool isDouble;

	for (int i = 0; i < 3; i++)
	{
		if (str == constants[i])
		{
			this->d = values[i];
			isDouble = true;
			intConvertible = false;
		}
	}
	if (!isDouble)
	{
		char const *s = str.c_str();
		s = consumeDouble(s);
		if (*s == '\0')
		{
			isDouble = true;
			std::stringstream ss(str);
			ss >> this->d;
		}
	}
	if (isDouble)
	{
		this->t = DOUBLE;
		this->c = static_cast<char>(this->d);
		this->i = static_cast<int>(this->d);
		this->f = static_cast<float>(this->d);
	}
	return isDouble;
}

bool Converter::fromChar(std::string const & str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		this->t = CHAR;
		this->c = str[1];
		this->i = static_cast<int>(this->c);
		this->f = static_cast<float>(this->c);
		this->d = static_cast<double>(this->c);
		return true;
	}
	return false;
}

void Converter::show()
{
	if (!this->intitialized)
		return ;
	if (this->t == UNKNOWN)
	{
		std::cout << "Given input is not of any acceped types" <<  std::endl;
		return ;
	}
	std::cout << "char: ";
	if (!this->intConvertible)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(this->c))
		std::cout << "'" << this->c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (!this->intConvertible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << this->f << 'f' << std::endl;
	std::cout << "double: " << this->d << std::endl;
	std::cout.clear();
}
