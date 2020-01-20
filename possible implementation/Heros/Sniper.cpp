//Sniper source

#include "Sniper.h"


Sniper::Sniper()
{
	heroId = sniper;
	damage = 4;
	health = 9;
	//it needs to pushBack itself in a vector
}

const us Sniper::getId()
{
	return this->heroId;
}
const us Sniper::getDamage()
{
	return this->damage;
}

void Sniper::attack()
{

}