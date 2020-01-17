#pragma once

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../generalDef.h"
#include <vector>

// dont touch anything
static enum class Players { P1, P2 };

class PlayerManager
{
public:
	PlayerManager();
	void changeTheTurn();
	Players getTheTurn();
	void displayPlayerInfo(sf::RenderWindow*);

	// players
	std::vector<Player*> playerVec;

private:
	// difine two player
	Player player1;
	Player player2;

	Players playerTurn;
	

};


#endif