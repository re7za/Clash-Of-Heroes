#pragma once

//Sybil header

#ifndef SYBIL_H
#define SYBIL_H

#include "Hero.h"

class Sybil : public Hero
{
public:
	Sybil();
	void attack();
	const us getId();
	const us getDamage();

private:

};

#endif 
