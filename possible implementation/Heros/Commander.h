#pragma once

//Commander header

#ifndef COMMANDER_H
#define COMMANDER_H

#include "Hero.h"

class Commander : public Hero
{
public:
	Commander(const sf::Vector2i&);
	void attack();
	const us getId();
	const us getDamage();

private:

};


#endif // !Commander
