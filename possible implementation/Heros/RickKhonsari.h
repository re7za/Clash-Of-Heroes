#pragma once

//RickKhonsari header

#ifndef RICKKHONSARI_H
#define RICKKHONSARI_H

#include "Hero.h"

class RickKhonsari : public Hero
{
public:
	RickKhonsari(const sf::Vector2i&);
	void attack(Hero* attackedHero, std::vector<Hero*>& attackedHeroesVec);


private:

};


#endif // !RickKhonsari
