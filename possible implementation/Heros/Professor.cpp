//Professor source

#include "Professor.h"


Professor::Professor()
{
	heroId = professor;
	damage = 3;
	health = 11;
	//it needs to pushBack itself in a vector
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