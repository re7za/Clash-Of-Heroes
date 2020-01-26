#pragma once

//AlphaMan header

#ifndef ALPHAMAN_H
#define ALPHAMAN_H

#include "Hero.h"

class AlphaMan : public Hero
{
public:
	AlphaMan(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);


private:

};


#endif // !AlphaMan
