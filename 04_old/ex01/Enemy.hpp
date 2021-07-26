#pragma once
#include <string>

class Enemy
{
private:
	void init();
protected:
	int			hp;
	std::string	type;
public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &);
	virtual ~Enemy();
	Enemy & operator=(Enemy const &);
	std::string const & getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};
