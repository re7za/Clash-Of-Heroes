#pragma once

//Professor header

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Hero.h"

class Professor : public Hero
{
public:
	Professor(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);


private:

};


#endif // !Professor
