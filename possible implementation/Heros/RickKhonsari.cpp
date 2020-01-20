//RickKhonsari source

#include "RickKhonsari.h"


RickKhonsari::RickKhonsari()
{
	heroId = rickKhonsari;
	damage = 3;
	health = 10;
	//it needs to pushBack itself in a vector
}

const us RickKhonsari::getId()
{
	return this->heroId;
}
const us RickKhonsari::getDamage()
{
	return this->damage;
}

void RickKhonsari::attack()
{

}