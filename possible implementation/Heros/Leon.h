#pragma once

//Leon header

#ifndef LEON_H
#define LEON_H

#include "Hero.h"

class Leon : public Hero
{
public:
	Leon(const sf::Vector2i&);
	void attack();
	const us getId();
	const us getDamage();

private:

};


#endif // !Leon
