#include "Converter.hpp"

Converter::Converter() : intitialized(false) {}

Converter::~Converter() {}

Converter::Converter(Converter const & other) = default;

Converter & Converter::operator=(Converter const & other) = default;

static char const *consumeMinus(char const *s)
{
	if (*s == '-')
		s++;
	return s;
}

static char const *consumeInt(char const *s)
{
	while (*s && std::isdigit(*s))
		s++;
	return s;
}

static bool isInt(std::string const & str)
{
	char const *s = str.c_str();
	s = consumeMinus(s);
	s = consumeInt(s);
	return (*s == '\0');
}

static bool isFloat(std::string const & str)
{
	char const *s = str.c_str();

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str.empty() || str == ".")
		return false;
	s = consumeInt(s);
	if (*(s++) != '.')
		return false;
	s = consumeInt(s);
	return (std::strcmp(s, "f") == 0);
}

static bool isDouble(std::string const & str)
{
	char const *s = str.c_str();

	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (str.empty() || str == ".")
		return false;
	s = consumeInt(s);
	if (*(s++) != '.')
		return false;
	s = consumeInt(s);
	return (*s == '\0');
}

static bool isChar(std::string const & str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}


void Converter::fromInt(std::string const & str)
{
	this->t = INT;
	std::stringstream ss(str);
	ss >> this->i;
	if (ss.fail())
	{
		std::cout << "Integer detected but overflow" << std::endl;
		this->t = UNKNOWN;
		return ;
	}
	this->c = static_cast<char>(this->i);
	if (this->i > CHAR_MAX || this->i < CHAR_MIN)
		this->charConvertible = false;
	this->f = static_cast<float>(this->i);
	this->d = static_cast<double>(this->i);
}

void Converter::fromFloat(std::string const & str)
{
	static char const *constants[3] = {
		"-inff", "+inff", "nanf"
	};
	static double const values[3] = {
		INFF_N, INFF_P, NANF
	};
	bool isConstant = false;

	for (int i = 0; i < 3; i++)
	{
		if (str == constants[i])
		{
			this->f = values[i];
			this->charConvertible = false;
			this->intConvertible = false;
			isConstant = true;
		}
	}
	if (!isConstant)
	{
		std::stringstream ss(str.substr(0, str.length() - 1));
		ss >> this->f;
		if (ss.fail())
		{
			std::cout << "Float detected but overflow" << std::endl;
			this->t = UNKNOWN;
			return ;
		}
	}
	this->t = FLOAT;
	this->c = static_cast<char>(this->f);
	if (this->f > CHAR_MAX || this->f < CHAR_MIN)
		this->charConvertible = false;
	this->i = static_cast<int>(this->f);
	if (this->f > INT_MAX_F || this->f < INT_MIN_F)
		this->intConvertible = false;
	this->d = static_cast<double>(this->f);
}

void Converter::fromDouble(std::string const & str)
{
	static char const *constants[3] = {
		"-inf", "+inf", "nan"
	};
	static double const values[3] = {
		INF_N, INF_P, NAN
	};
	bool isConstant = false;

	for (int i = 0; i < 3; i++)
	{
		if (str == constants[i])
		{
			this->d = values[i];
			this->charConvertible = false;
			this->intConvertible = false;
			isConstant = true;
		}
	}
	if (!isConstant)
	{
		std::stringstream ss(str);
		ss >> this->d;
		if (ss.fail())
		{
			std::cout << "Double detected but overflow" << std::endl;
			this->t = UNKNOWN;
			return ;
		}
	}
	this->t = DOUBLE;
	this->c = static_cast<char>(this->d);
	if (this->d > CHAR_MAX || this->d < CHAR_MIN)
		this->charConvertible = false;
	this->i = static_cast<int>(this->d);
	if (this->d > INT_MAX_D || this->d < INT_MIN_D)
		this->intConvertible = false;
	this->f = static_cast<float>(this->d);
	if (this->d > FLOAT_MAX_D || this->d < -FLOAT_MAX_D)
		this->floatConvertible = false;
}

void Converter::fromChar(std::string const & str)
{
	this->t = CHAR;
	this->c = str[1];
	this->i = static_cast<int>(this->c);
	this->f = static_cast<float>(this->c);
	this->d = static_cast<double>(this->c);
}

Converter & Converter::fromString(std::string const & str)
{
	this->charConvertible = true;
	this->intConvertible = true;
	this->floatConvertible = true;
	if (isChar(str))
		this->fromChar(str);
	else if (isInt(str))
		this->fromInt(str);
	else if (isFloat(str))
		this->fromFloat(str);
	else if (isDouble(str))
		this->fromDouble(str);
	else
		this->t = UNKNOWN;
	this->intitialized = true;
	return *this;
}

void Converter::show()
{
	if (!this->intitialized)
		return ;
	if (this->t == UNKNOWN)
	{
		std::cout << "Given input is not of any acceped types or it overflows" <<  std::endl;
		return ;
	}
	std::cout << "char: ";
	if (!this->charConvertible)
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
	std::cout << "float: ";
	if (!this->floatConvertible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->f << 'f' << std::endl;
	std::cout << "double: " << this->d << std::endl;
	std::cout.clear();
}
