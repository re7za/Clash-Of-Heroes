#pragma once

//Professor header

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Hero.h"

class Professor : public Hero
{
public:
	Professor(const sf::Vector2i&);
	void attack();
	const us getId();
	const us getDamage();

private:

};


#endif // !Professor
