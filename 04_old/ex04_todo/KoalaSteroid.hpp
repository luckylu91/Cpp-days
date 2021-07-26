#pragma once
#include "IAsteroid.hpp"
#include <iostream>

class KoalaSteroid : public IAsteroid
{
public:
	std::string beMined(DeepCoreMiner *) const;
	std::string beMined(StripMiner *) const;
	std::string getName();
};

KoalaSteroid::KoalaSteroid() {}

KoalaSteroid::KoalaSteroid(KoalaSteroid const &other) {}

KoalaSteroid::~KoalaSteroid() {}

KoalaSteroid &KoalaSteroid::operator=(KoalaSteroid const &other) { return *this; }

std::string KoalaSteroid::beMined(DeepCoreMiner *) const
{
	return "Dragonite";
}

std::string KoalaSteroid::beMined(StripMiner *) const
{
	return "Flavium";
}

std::string KoalaSteroid::getName()
{
	return "KoalaSteroid";
}
