//Professor source

#include "Professor.h"


Professor::Professor(const sf::Vector2i& pos)
{
	heroId = professor;
	damage = 3;
	health = 11;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us Professor::getId()
{
	return this->heroId;
}
const us Professor::getDamage()
{
	return this->damage;
}

void Professor::attack()
{

}