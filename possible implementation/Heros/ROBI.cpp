//ROBI source

#include "ROBI.h"


ROBI::ROBI(const sf::Vector2i& pos)
{
	heroId = robi;
	damage = 2;
	health = 12;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}


void ROBI::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
{
	///////////////// general hits
	attackedHero->setHideness(false);
	attackedHero->decreaseHealth(this->damage);

	///////////////// abnormal under attack heroes
	// Leon special property
	if (attackedHero->getId() == heros::leon)
		this->decreaseHealth(2);

	// Professor special property
	if (attackedHero->getId() == heros::professor)
		this->hideness = false;

	///////////////// attacker special power
}