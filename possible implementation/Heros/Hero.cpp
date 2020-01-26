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
{
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
		this->hideness = false;	//its not hidden anymore
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

void Hero::setHideness(bool newHideness)
{
	this->hideness = newHideness;
}
bool Hero::isHidden()
{
	return this->hideness;
}

void Hero::setReadiness(bool newReadiness)
{
	this->readiness = newReadiness;
}
bool Hero::isReady()
{
	return this->readiness;
}

// hero position in grid
void Hero::setHeroPosition(const sf::Vector2i &pos)
{
	heroPos = pos;
}
sf::Vector2i Hero::getHeroPosition()
{
	return heroPos;
}

