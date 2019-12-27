#pragma once

//ROBI header

#ifndef ROBI_H
#define ROBI_H

#include "Hero.h"

class ROBI : public Hero
{
public:
	ROBI();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = robi;
	const us damage = 2;

};


#endif // !ROBI_H
