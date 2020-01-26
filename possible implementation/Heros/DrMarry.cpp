//DrMarry source

#include "DrMarry.h"


DrMarry::DrMarry(const sf::Vector2i& pos)
{
	heroId = drMarry;
	damage = 2;
	health = 8;

	// hero position in grid
	setHeroPosition(pos);
}


void DrMarry::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
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
	this->health += 2;
}