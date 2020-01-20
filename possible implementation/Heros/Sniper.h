#pragma once

//Sniper header

#ifndef SNIPER_H
#define SNIPER_H

#include "Hero.h"

class Sniper : public Hero
{
public:
	Sniper();
	void attack();
	const us getId();
	const us getDamage();

private:

};


#endif // !Sniper
