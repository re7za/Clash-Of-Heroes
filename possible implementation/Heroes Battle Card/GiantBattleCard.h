#pragma once

#ifndef GIANTBATTLECARD_H
#define GIANTBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class GiantBattleCard : public BattleCard
{
public:
	GiantBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

	void anotherClick();
	us getTheClickSituation();
	void resetTheClickSituation();

private:

	// special power : Instead of attacking..
	us secondClick = 0;
};


#endif 
