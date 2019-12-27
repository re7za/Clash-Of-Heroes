#pragma once

//Giant header

#ifndef GIANT_H
#define GIANT_H

#include "Hero.h"

class Giant : public Hero
{
public:
	Giant();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = giant;
	const us damage = 4;

};


#endif // !Giant
