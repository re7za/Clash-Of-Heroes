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

private:
	// difine two player
	Player player1;
	Player player2;
	std::vector<Player*> playerVec;

	Players playerTurn;
	

};


#endif