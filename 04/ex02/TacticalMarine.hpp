#pragma once
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
private:
	void _init();
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &);
	~TacticalMarine();
	TacticalMarine & operator=(TacticalMarine const &);
	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};
