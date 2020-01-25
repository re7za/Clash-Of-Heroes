#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"

class Hero
{
public:
	virtual void attack() = 0;
	heros getId();
	us getDamage();
	us getHealth();

	void decreaseHealth(us damage);
	//it isn't unsigned.. maybe sometimes we need it to be a increaseHealth() =)
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
	bool hiding = true;	//true means its hidden
	bool readiness = true;
	
	// hero position in grid
	sf::Vector2i heroPos;
};


#endif // !Hero
