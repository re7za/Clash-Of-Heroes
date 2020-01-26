//AlphaMan source

#include "AlphaMan.h"


AlphaMan::AlphaMan(const sf::Vector2i& pos)
{
	heroId = alphaMan;
	damage = 2;
	health = 13;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

void AlphaMan::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
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

void AlphaMan::specialPower(std::vector<Hero*>& attackedHeroesVec, sf::Vector2i attackPos)
{
	///////////////// attacker special power : Turn on corner houses
	for (Hero* attacked : attackedHeroesVec)
	{
		if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x, attackPos.y - 1))
			attacked->decreaseHealth(1);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x, attackPos.y + 1))
			attacked->decreaseHealth(1);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x - 1, attackPos.y))
			attacked->decreaseHealth(1);
		else if (attacked->getHeroPosition() == sf::Vector2i(attackPos.x + 1, attackPos.y))
			attacked->decreaseHealth(1);
	}
}
