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

}

void ROBI::specialPower(std::vector<Hero*>& attackedHeroesVec, sf::Vector2i attackPos)
{
	///////////////// attacker special power : Turn on corner houses
	for (Hero* attacked : attackedHeroesVec)
	{
		if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x - 1, attackPos.y - 1))
			attacked->setHideness(false);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x + 1, attackPos.y - 1))
			attacked->setHideness(false);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x - 1, attackPos.y + 1))
			attacked->setHideness(false);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x + 1, attackPos.y + 1))
			attacked->setHideness(false);

		if (attacked->getId() == heros::mrsGhost)	// special case : Mrs.Ghost
		{
			if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x - 1, attackPos.y - 1))
				attacked->setHideness(false);
			else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x + 1, attackPos.y - 1))
				attacked->setHideness(false);
			else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x - 1, attackPos.y + 1))
				attacked->setHideness(false);
			else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x + 1, attackPos.y + 1))
				attacked->setHideness(false);
		}
	}
}
