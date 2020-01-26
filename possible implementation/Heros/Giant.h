#pragma once

//Giant header

#ifndef GIANT_H
#define GIANT_H

#include "Hero.h"

class Giant : public Hero
{
public:
	Giant(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);


private:

};


#endif // !Giant
