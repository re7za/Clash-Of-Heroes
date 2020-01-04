#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "../Grid/Grid.h"
#include "../Menus/MenuManager.h"

class Player
{
public:
	Player();
	void display(sf::RenderWindow*, MenuManager&);


private:

	// each player has a grid
	Grid grid;

};


#endif