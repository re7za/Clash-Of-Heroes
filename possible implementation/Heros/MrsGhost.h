#pragma once

//Mrs.Ghoast header

#ifndef MRSGHOST_H
#define MRSGHOST_H

#include "Hero.h"

class MrsGhost : public Hero
{
public:
	MrsGhost(const sf::Vector2i&);
	void attack();
	const us getId();
	const us getDamage();
	void setHiding(bool) override;

private:
	bool invisibleShield = true;

};


#endif // !MRSGHOST_H
