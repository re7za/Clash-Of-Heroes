//AlphaMan source

#include "AlphaMan.h"


AlphaMan::AlphaMan()
{
	health = 13;
	//it needs to pushBack itself in a vector
}

const us AlphaMan::getId()
{
	return this->heroId;
}
const us AlphaMan::getDamage()
{
	return this->damage;
}

void AlphaMan::attack()
{

}