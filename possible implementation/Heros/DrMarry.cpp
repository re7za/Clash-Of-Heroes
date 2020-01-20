//DrMarry source

#include "DrMarry.h"


DrMarry::DrMarry(const sf::Vector2i& pos)
{
	heroId = drMarry;
	damage = 2;
	health = 8;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us DrMarry::getId()
{
	return this->heroId;
}
const us DrMarry::getDamage()
{
	return this->damage;
}

void DrMarry::attack()
{

}