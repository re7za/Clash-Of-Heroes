
#include "Player.h"

Player::Player()
{

}

void Player::removeHero(heros heroName)
{
	for (us i = 0; i < playerHerosVec.size(); i++)
		if (playerHerosVec.at(i)->getId() == heroName)
		{
			playerHerosVec.erase(playerHerosVec.begin() + i);
			break;
		}
}
