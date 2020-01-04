#pragma once

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "../Menus/MenuManager.h"
#include "../generalDef.h"

static enum class Players { P1, P2 };

class PlayerManager
{
public:
	PlayerManager();
	void changeTheTurn();
	Players getTheTurn();
	void displayPlayerInfo(sf::RenderWindow*, MenuManager&);

private:
	// difine two player
	Player player1;
	Player player2;
	
	Players playerTurn;
	

};


#endif