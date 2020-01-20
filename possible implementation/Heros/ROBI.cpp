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

const us ROBI::getId()
{
	return this->heroId;
}
const us ROBI::getDamage()
{
	return this->damage;
}


void ROBI::attack()
{

}