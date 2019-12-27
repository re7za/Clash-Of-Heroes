//Kratos source

#include "Kratos.h"


Kratos::Kratos()
{
	health = 15;
	//it needs to pushBack itself in a vector
}

const us Kratos::getId()
{
	return this->heroId;
}
const us Kratos::getDamage()
{
	return this->damage;
}

void Kratos::attack()
{

}