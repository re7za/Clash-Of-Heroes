//Hero source

#include "Hero.h"


Hero::~Hero() {}

heros Hero::getId()
{
	return this->heroId;
}
us Hero::getDamage()
{
	return this->damage;
}
us Hero::getHealth()
{
	return this->health;
}

void Hero::decreaseHealth(us damage)
{// ریدی با این تابع.. چک کن اگه مصلا یکه صفر شه
	if (this->health <= maxHealth)
	{
		this->health -= damage;
		checkAliveness();
	}
}

void Hero::checkAliveness()
{
	if (this->health == 0 || this->health > maxHealth
		|| this->aliveness == false)
	{
		this->health = 0;
		this->aliveness = false;
		this->hiding = false;	//its not hidden anymore
		this->readiness = false;
	}
}
void Hero::setAliveness(bool newAliveness)
{
	this->aliveness = newAliveness;
	checkAliveness();
}
bool Hero::isAlive()
{
	return this->aliveness;
}

void Hero::setHiding(bool newHidingSituation)
{
	this->hiding = newHidingSituation;
}
bool Hero::isHidden()
{
	return this->hiding;
}

void Hero::setReadiness(bool newReadiness)
{
	this->readiness = newReadiness;
}
bool Hero::isReady()
{
	return this->readiness;
}

