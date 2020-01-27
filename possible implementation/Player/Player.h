#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "../Heros/AlphaMan.h"
#include "../Heros/Commander.h"
#include "../Heros/DrMarry.h"
#include "../Heros/Giant.h"
#include "../Heros/Kratos.h"
#include "../Heros/Leon.h"
#include "../Heros/MrsGhost.h"
#include "../Heros/Professor.h"
#include "../Heros/RickKhonsari.h"
#include "../Heros/ROBI.h"
#include "../Heros/Sniper.h"
#include "../Heros/Sybil.h"
#include "../Heros/Hero.h"
#include <vector>
#include <iostream>


struct attacekPosStatus
{
	sf::Vector2i pos;
	tileType status = tileType::L1;
};


class Player
{
public:
	Player();

	// set hero
	bool isHeroExistInVec(heros);

	// remove hero
	void removeHero(heros);

	// the end of selection menu
	bool isPlayerHeroVecFull();

	// it must be public
	heros attackedHero = heros::none;

	// player vector
	std::vector <Hero*> playerHerosVec;
	// attaced positions
	std::vector<attacekPosStatus> attackPosStatucVec;

	// attack pos methods
	void setAttackPos(sf::Vector2i);
	sf::Vector2i getAttackPos();

private:

	// attack position.. هیج دلیلی ندارم برای پرایوت تعریف کردنش وقتی هیج چکینگی قرار نیس روش انجام شه.. هزینه الکیه
	sf::Vector2i attackPos;


};


#endif