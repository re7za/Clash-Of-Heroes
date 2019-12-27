#pragma once

//Commander header

#ifndef COMMANDER_H
#define COMMANDER_H

#include "Hero.h"

class Commander : public Hero
{
public:
	Commander();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = commander;
	const us damage = 3;

};


#endif // !Commander
