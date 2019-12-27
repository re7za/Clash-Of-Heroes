//Commander source

#include "Commander.h"


Commander::Commander()
{
	health = 7;
	//it needs to pushBack itself in a vector
}

const us Commander::getId()
{
	return this->heroId;
}
const us Commander::getDamage()
{
	return this->damage;
}

void Commander::attack()
{

}