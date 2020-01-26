#pragma once

//Commander header

#ifndef COMMANDER_H
#define COMMANDER_H

#include "Hero.h"

class Commander : public Hero
{
public:
	Commander(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);


private:

};


#endif // !Commander
