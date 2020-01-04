#include "PlayerManager.h"
#include <iostream>

PlayerManager::PlayerManager()
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

void PlayerManager::displayPlayerInfo(sf::RenderWindow* window, MenuManager& menuManager)
{
	if (getTheTurn() == Players::P1)
		player1.display(window, menuManager);
	else
		player2.display(window, menuManager);

}
