#pragma once
#include <string>

class Karen
{
private:
	typedef void (Karen::*complaint_fun_t)(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	void complain( std::string level );
};
