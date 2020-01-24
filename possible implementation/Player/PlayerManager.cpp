#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	// playerVec
	playerArr.at(0) = &player1;
	playerArr.at(1) = &player2;

	// default turn for selection menu
	playerTurn = Players::P1;
	attackedPlayer = Players::P2;
}

void PlayerManager::headsOrTails()
{
	// Heads or Tails
	if (rand() % 2 == 0)
	{
		playerTurn = Players::P1;
		attackedPlayer = Players::P2;
	}
	else
	{
		playerTurn = Players::P2;	// حواست باشه منوی هیرو سلکشن نباید بصورت رندوم باشه
		attackedPlayer = Players::P1;
	}

}
void PlayerManager::changeTheTurn()
{
	if (playerTurn == Players::P1)
	{
		playerTurn = Players::P2;
		attackedPlayer = Players::P1;
	}
	else
	{
		playerTurn = Players::P1;
		attackedPlayer = Players::P2;
	}
}
Players PlayerManager::getTheTurn()
{
	return playerTurn;
}

Players PlayerManager::getAttackedPlayer()
{
	return attackedPlayer;
}

void PlayerManager::setTheChosenHeroes()
{
	// P1
	for (us i = 0; i < player1.playerHerosVec.size(); i++)
		chosenHeroes.at(i) = player1.playerHerosVec.at(i)->getId();

	// P2
	for (us i = 0; i < player2.playerHerosVec.size(); i++)
		chosenHeroes.at(i + 5) = player2.playerHerosVec.at(i)->getId();	
}

std::array<heros, 10> PlayerManager::getTheChosenHeroes()
{
	return chosenHeroes;
}
