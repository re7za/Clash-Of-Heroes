#pragma once

//AlphaMan header

#ifndef ALPHAMAN_H
#define ALPHAMAN_H

#include "Hero.h"

class AlphaMan : public Hero
{
public:
	AlphaMan();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = alphaMan;
	const us damage = 2;

};


#endif // !AlphaMan
