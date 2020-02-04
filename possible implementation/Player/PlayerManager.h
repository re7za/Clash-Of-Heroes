#pragma once

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../generalDef.h"
#include <array>

// dont touch anything
static enum class Players { P1 = 0, P2 };

class PlayerManager
{
public:
	PlayerManager();
	void headsOrTails();
	void changeTheTurn();
	Players getTheTurn();
	Players getAttackedPlayer();

	void setTheChosenHeroes();
	void clearheChosenHeroes();
	void clearPlayerMemory();
	std::array<heros, 10> getTheChosenHeroes();

	// players
	std::array<Player*, 2> playerArr;

private:
	// difine two player
	Player player1;
	Player player2;

	Players playerTurn;
	Players attackedPlayer;
	
	std::array<heros, 10> chosenHeroes;

};


#endif