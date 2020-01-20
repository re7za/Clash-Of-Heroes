//Giant source

#include "Giant.h"


Giant::Giant(const sf::Vector2i& pos)
{
	heroId = giant;
	damage = 4;
	health = 20;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us Giant::getId()
{
	return this->heroId;
}
const us Giant::getDamage()
{
	return this->damage;
}

void Giant::attack()
{

}