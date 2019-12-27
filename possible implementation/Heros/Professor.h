#pragma once

//Professor header

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Hero.h"

class Professor : public Hero
{
public:
	Professor();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = professor;
	const us damage = 3;

};


#endif // !Professor
