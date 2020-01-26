#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"
#include <iostream>

class Hero
{
public:
	virtual void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec) = 0;
	// create a 'void specialPower()' for some heroes that have special power... like sniper.. robi.. etc
	heros getId();
	us getDamage();
	us getHealth();

	void decreaseHealth(us damage);
	//it isn't unsigned.. maybe sometimes we need it to be an increaseHealth() =)
	void checkAliveness();	//set the aliveness to false if getHealth == 0
	void setAliveness(bool);	//to die suddenly.. for ex by sniper
	bool isAlive();
	virtual void setHideness(bool);
	bool isHidden();
	void setReadiness(bool);
	bool isReady();

	// hero position in grid
	void setHeroPosition(const sf::Vector2i&);
	sf::Vector2i getHeroPosition();


	virtual ~Hero();

protected:
	heros heroId;
	us health;
	us damage;
	bool aliveness = true;
	bool hideness = true;	//true means its hidden
	bool readiness = true;
	
	// hero position in grid
	sf::Vector2i heroPos;
};


#endif // !Hero
