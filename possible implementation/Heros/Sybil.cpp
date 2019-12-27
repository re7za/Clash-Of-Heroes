//Sybil source

#include "Sybil.h"


Sybil::Sybil()
{
	health = 12;
	//it needs to pushBack itself in a vector
}

const us Sybil::getId()
{
	return this->heroId;
}
const us Sybil::getDamage()
{
	return this->damage;
}

void Sybil::attack()
{

}