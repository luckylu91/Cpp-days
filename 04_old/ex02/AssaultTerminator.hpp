#pragma once
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
private:
	void _init();
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &);
	~AssaultTerminator();
	AssaultTerminator & operator=(AssaultTerminator const &);
	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};
