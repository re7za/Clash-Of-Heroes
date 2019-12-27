#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

#include "Heros/generalDef.h"

class Hero
{
public:
	virtual void attack() = 0;
	virtual const us getId();
	virtual const us getDamage();

	void decreaseHealth(us);
	us getHealth();
	void checkAliveness();	//set the aliveness to false if get health == 0
	void setAliveness(bool);	//to die suddenly.. for ex to die by sniper
	bool isAlive();
	virtual void setHiding(bool);
	bool isHidden();
	void setReadiness(bool);
	bool isReady();

	virtual ~Hero();

protected:
	const us heroId = 0;
	const us damage = 0;
	us health;
	bool aliveness = true;
	bool hiding = false;	//true means hidden
	bool readiness = true;
	

};


#endif // !Hero
