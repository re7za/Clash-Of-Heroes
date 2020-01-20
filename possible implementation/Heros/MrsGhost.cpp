//MrsGhost source

#include "MrsGhost.h"


MrsGhost::MrsGhost()
{
	heroId = mrsGhost;		//enum heros::mrsGhost = 0
	damage = 3;
	health = 15;
	//it needs to pushBack itself in a vector
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

void MrsGhost::setHiding(bool newHidingSituation)
{
	if (invisibleShield == true)
	{
		invisibleShield = false;
		return;
	}
	else
		this->hiding = newHidingSituation;
}

