#pragma once

//ROBI header

#ifndef ROBI_H
#define ROBI_H

#include "Hero.h"

class ROBI : public Hero
{
public:
	ROBI(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);
	void specialPower(std::vector<Hero*>& attackedHeroesVec, sf::Vector2i attackPos);


private:

};


#endif // !ROBI_H
