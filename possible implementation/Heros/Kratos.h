#pragma once

//Kratos header

#ifndef KRATOS_H
#define KRATOS_H

#include "Hero.h"

class Kratos : public Hero
{
public:
	Kratos();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = kratos;
	const us damage = 3;

};


#endif // !Kratos
