//Leon source

#include "Leon.h"


Leon::Leon(const sf::Vector2i& pos)
{
	heroId = leon;
	damage = 3;
	health = 10;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us Leon::getId()
{
	return this->heroId;
}
const us Leon::getDamage()
{
	return this->damage;
}

void Leon::attack()
{

}