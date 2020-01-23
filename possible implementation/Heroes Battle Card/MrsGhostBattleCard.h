#pragma once

#ifndef MrsGhostBATTLECARD_H
#define MrsGhostBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class MrsGhostBattleCard : public BattleCard
{
public:
	MrsGhostBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
