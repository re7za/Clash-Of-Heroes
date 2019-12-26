#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

#include "generalDef.h"

class Hero
{
public:
	virtual void attack() = 0;
	void decreaseHealth(us);
	us getDamage();
	us getHealth();
	void checkAliveness();	//set the aliveness to false if get health == 0
	void setAliveness(bool);	//to die suddenly.. for ex to die by sniper
	bool isAlive();
	void setHiding(bool);
	bool isHidden();
	void setReadiness(bool);
	bool isReady();

protected:
	const us damage = 0;
	us health;
	bool aliveness;
	bool hiding;	//true means hidden
	bool readiness;

};


#endif // !Hero
