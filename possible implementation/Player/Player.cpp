
#include "Player.h"

Player::Player()
{

}

bool Player::isHeroExistInVec(heros heroName)
{
	for (Hero*& i : playerHerosVec)
		if (i->getId() == heroName)
			return true;
	
	return false;
}

void Player::removeHero(heros heroName)
{
	for (us i = 0; i < playerHerosVec.size(); i++)
		if (playerHerosVec.at(i)->getId() == heroName)
		{
			delete playerHerosVec.at(i);
			playerHerosVec.erase(playerHerosVec.begin() + i);
			break;
		}
	playerHerosVec.shrink_to_fit();
}

bool Player::isPlayerHeroVecFull()
{
	if (playerHerosVec.size() == 5)
		return true;

	return false;
}

void Player::setAttackPos(sf::Vector2i pos)
{
		attackPos = pos;
}

sf::Vector2i Player::getAttackPos()
{
	return attackPos;
}

