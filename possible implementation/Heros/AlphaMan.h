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
	void specialPower(std::vector<Hero*>& attackedHeroesVec, sf::Vector2i attackPos);


private:

};


#endif // !AlphaMan
