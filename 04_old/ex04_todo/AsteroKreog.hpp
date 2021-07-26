#pragma once
#include "IAsteroid.hpp"
#include <iostream>

class AsteroKreog : public IAsteroid
{
public:
	std::string beMined(DeepCoreMiner *) const;
	std::string beMined(StripMiner *) const;
	std::string getName();
};

AsteroKreog::AsteroKreog() {}

AsteroKreog::AsteroKreog(AsteroKreog const &other) {}

AsteroKreog::~AsteroKreog() {}

AsteroKreog &AsteroKreog::operator=(AsteroKreog const &other) { return *this; }

std::string AsteroKreog::beMined(DeepCoreMiner *) const
{
	return "Meium";
}

std::string AsteroKreog::beMined(StripMiner *) const
{
	return "Tartarite";
}

std::string AsteroKreog::getName()
{
	return "AsteroKreog";
}
