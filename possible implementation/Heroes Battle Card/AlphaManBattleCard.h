#pragma once

#ifndef ALPHAMANBATTLECARD_H
#define ALPHAMANBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class AlphaManBattleCard : public BattleCard
{
public:
	AlphaManBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
