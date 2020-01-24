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


//#include "../Menus/MenuManager.h"

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


private:

};


#endif