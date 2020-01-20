#pragma once

//Kratos header

#ifndef KRATOS_H
#define KRATOS_H

#include "Hero.h"

class Kratos : public Hero
{
public:
	Kratos(const sf::Vector2i&);
	void attack();
	const us getId();
	const us getDamage();

private:

};


#endif // !Kratos
