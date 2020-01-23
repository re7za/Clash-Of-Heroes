#pragma once

#ifndef DRMARRYBATTLECARD_H
#define DRMARRYBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class DrMarryBattleCard : public BattleCard
{
public:
	DrMarryBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
