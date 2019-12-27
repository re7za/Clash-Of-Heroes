//DrMarry source

#include "DrMarry.h"


DrMarry::DrMarry()
{
	health = 8;
	//it needs to pushBack itself in a vector
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