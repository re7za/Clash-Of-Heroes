//RickKhonsari source

#include "RickKhonsari.h"


RickKhonsari::RickKhonsari(const sf::Vector2i& pos)
{
	heroId = rickKhonsari;
	damage = 3;
	health = 10;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

const us RickKhonsari::getId()
{
	return this->heroId;
}
const us RickKhonsari::getDamage()
{
	return this->damage;
}

void RickKhonsari::attack()
{

}