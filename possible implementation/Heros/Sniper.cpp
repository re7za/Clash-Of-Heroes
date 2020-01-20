//Sniper source

#include "Sniper.h"


Sniper::Sniper(const sf::Vector2i& pos)
{
	heroId = sniper;
	damage = 4;
	health = 9;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us Sniper::getId()
{
	return this->heroId;
}
const us Sniper::getDamage()
{
	return this->damage;
}

void Sniper::attack()
{

}