#pragma once

//RickKhonsari header

#ifndef RICKKHONSARI_H
#define RICKKHONSARI_H

#include "Hero.h"

class RickKhonsari : public Hero
{
public:
	RickKhonsari();
	void attack();
	const us getId();
	const us getDamage();

private:
	const us heroId = rickKhonsari;
	const us damage = 3;

};


#endif // !RickKhonsari
