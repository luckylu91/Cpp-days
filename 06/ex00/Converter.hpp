#pragma once
#include <iostream>
#include <sstream>
#include <cstring>
#include <limits>
#include <cmath>
#include <iomanip>

class Converter
{
private:
	typedef enum e_type_from {CHAR, INT, FLOAT, DOUBLE, UNKNOWN} t_type_from;
	bool		intitialized;
	bool		intConvertible;
	char 		c;
	int 		i;
	float 		f;
	double 		d;
	t_type_from	t;
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
	Converter & operator=(Converter const &);
	~Converter();
	Converter & fromString(std::string const & str);
	void show();
};
