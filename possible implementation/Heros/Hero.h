#pragma once

//Hero header

#ifndef HERO_H
#define HERO_H

#include "generalDef.h"

class Hero
{
public:
	virtual void attack() = 0;
	virtual const us getId();
	virtual const us getDamage();

	void decreaseHealth(short);	//it isn't unsigned.. maybe sometimes we need it to be a increaseHealth() =)
	us getHealth();
	void checkAliveness();	//set the aliveness to false if getHealth == 0
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
