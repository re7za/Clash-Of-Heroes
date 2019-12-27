//ROBI source

#include "ROBI.h"


ROBI::ROBI()
{
	health = 12;
	//it needs to pushBack itself in a vector
}

const us ROBI::getId()
{
	return this->heroId;
}
const us ROBI::getDamage()
{
	return this->damage;
}


void ROBI::attack()
{

}