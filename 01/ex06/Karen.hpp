#include <string>

class Karen
{
private:
	typedef void (Karen::*complaint_fun_t)(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void unknown( void );
public:
	void complain_starting_at( std::string level );
};
