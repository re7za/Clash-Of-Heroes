//Leon source

#include "Leon.h"


Leon::Leon()
{
	health = 10;
	//it needs to pushBack itself in a vector
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