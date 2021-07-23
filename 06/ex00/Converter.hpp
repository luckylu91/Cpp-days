#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <limits>
#include <cmath>
#include <climits>
#include <cfloat>

#define INFF_N	std::numeric_limits<float>::min()
#define INFF_P	std::numeric_limits<float>::max()
#define NANF	nanf("")
#define INF_N	std::numeric_limits<double>::min()
#define INF_P	std::numeric_limits<double>::max()
// #define NAN		nan("")

#define INT_MAX_F static_cast<float>(INT_MAX)
#define INT_MIN_F static_cast<float>(INT_MIN)
#define INT_MAX_D static_cast<double>(INT_MAX)
#define INT_MIN_D static_cast<double>(INT_MIN)
#define FLOAT_MAX_D static_cast<double>(FLT_MAX)

class Converter
{
private:
	typedef enum e_type_from {CHAR, INT, FLOAT, DOUBLE, UNKNOWN} t_type_from;
	bool		intitialized;
	bool		charConvertible;
	bool		intConvertible;
	bool		floatConvertible;
	char 		c;
	int 		i;
	float 		f;
	double 		d;
	t_type_from	t;
	void fromInt(std::string const & str);
	void fromFloat(std::string const & str);
	void fromDouble(std::string const & str);
	void fromChar(std::string const & str);
public:
	Converter();
	Converter(Converter const &);
	Converter & operator=(Converter const &);
	~Converter();
	Converter & fromString(std::string const & str);
	void show();
};
