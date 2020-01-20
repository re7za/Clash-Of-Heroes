#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

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
	virtual void setHiding(bool);
	bool isHidden();
	void setReadiness(bool);
	bool isReady();

	virtual ~Hero();

protected:
	heros heroId;
	us health;
	us damage;
	bool aliveness = true;
	bool hiding = false;	//true means hidden
	bool readiness = true;
	
};


#endif // !Hero
