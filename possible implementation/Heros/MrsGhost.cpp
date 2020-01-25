//MrsGhost source

#include "MrsGhost.h"


MrsGhost::MrsGhost(const sf::Vector2i& pos)
{
	heroId = mrsGhost;		//enum heros::mrsGhost = 0
	damage = 3;
	health = 15;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}

void MrsGhost::attack()
{
	
}

const us MrsGhost::getId()
{
	return this->heroId;
}
const us MrsGhost::getDamage()
{
	return this->damage;
}

void MrsGhost::setHideness(bool Hideness)
{
	if (invisibleShield == true)
	{
		invisibleShield = false;
		return;
	}
	else
		this->hiding = Hideness;
}

