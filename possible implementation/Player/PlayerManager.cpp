#include "PlayerManager.h"
#include <iostream>

PlayerManager::PlayerManager()
{
	// playerVec
	playerArr.at(0) = &player1;
	playerArr.at(1) = &player2;

	// default turn for selection menu
	playerTurn = Players::P1;
}

void PlayerManager::headsOrTails()
{
	// Heads or Tails
	if (rand() % 2 == 0)
		playerTurn = Players::P1;
	else
		playerTurn = Players::P2;	// حواست باشه منوی هیرو سلکشن نباید بصورت رندوم باشه

}

void PlayerManager::changeTheTurn()
{
	if (playerTurn == Players::P1)
		playerTurn = Players::P2;
	else
		playerTurn = Players::P1;
}
Players PlayerManager::getTheTurn()
{
	return playerTurn;
}

void PlayerManager::displayPlayerInfo(sf::RenderWindow* window)
{

}
