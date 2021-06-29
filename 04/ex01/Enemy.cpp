#include "Enemy.hpp"
#include <string>
#include <iostream>

void Enemy::init()
{
	std::cout << "A new " << type << " entered the ring!" << std::endl;
}

Enemy::Enemy(int hp, std::string const & type) : hp(hp), type(type) { init(); }

Enemy::Enemy(Enemy const & other) : hp(other.hp), type(other.type) { init(); }

Enemy::~Enemy()
{
	std::cout << "A " << type << " just died... RIP loser." << std::endl;
}

Enemy & Enemy::operator=(Enemy const & other)
{
	hp = other.hp;
	type = other.type;
	return *this;
}
std::string const & Enemy::getType() const
{
	return type;
}

int Enemy::getHP() const
{
	return hp;
}

void Enemy::takeDamage(int damage)
{
	if (damage <= 0)
	{
		std::cout << "Nothing happend." << std::endl;
	}
	else if (hp == 0)
	{
		std::cout << "The corpse of a " << type << " was unrighfully beaten even further" << std::endl;
	}
	else if (damage >= hp)
	{
		hp = 0;
		std::cout << "The Enemy (of type " << type << ") has just died. Oh my." << std::endl;
	}
	else
	{
		hp -= damage;
		std::cout << "The Enemy (of type " << type << ") has " << hp << " hp left" << std::endl;
	}
}
