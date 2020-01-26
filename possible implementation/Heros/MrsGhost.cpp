//MrsGhost source

#include "MrsGhost.h"


MrsGhost::MrsGhost(const sf::Vector2i& pos)
{
	heroId = mrsGhost;		//enum heros::mrsGhost = 0
	damage = 3;
	health = 15;

	// hero position in grid
	setHeroPosition(pos);
}

void MrsGhost::setHideness(bool Hideness)
{
	if (invisibleShield == true)
	{
		invisibleShield = false;
		return;
	}
	else
		this->hideness = Hideness;
}


void MrsGhost::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
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
