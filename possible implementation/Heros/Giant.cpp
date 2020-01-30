//Giant source

#include "Giant.h"


Giant::Giant(const sf::Vector2i& pos)
{
	heroId = giant;
	damage = 4;
	health = 16;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}


void Giant::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
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

}

void Giant::HellBoyMode(Hero* teammate)
{
	///////////////// attacker special power : Three units decrease his health and add to his teammate

	this->decreaseHealth(3);
	teammate->increaseHealth(3);
}
