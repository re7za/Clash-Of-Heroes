//Sybil source

#include "Sybil.h"


Sybil::Sybil(const sf::Vector2i& pos)
{
	heroId = sybil;
	damage = 2;
	health = 12;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us Sybil::getId()
{
	return this->heroId;
}
const us Sybil::getDamage()
{
	return this->damage;
}

void Sybil::attack()
{

}