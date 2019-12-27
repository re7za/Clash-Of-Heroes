//Giant source

#include "Giant.h"


Giant::Giant()
{
	health = 20;
	//it needs to pushBack itself in a vector
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