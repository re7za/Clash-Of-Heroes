//Kratos source

#include "Kratos.h"


Kratos::Kratos(const sf::Vector2i& pos)
{
	heroId = kratos;
	damage = 3;
	health = 15;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}


void Kratos::attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec)
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

void Kratos::AvatarMode(Hero* teammate, sf::Vector2i newPos)
{
	///////////////// attacker special power : replace his timmate
	teammate->setHeroPosition(newPos);
	teammate->setHideness(true);
}
