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
	void usingKey();

private:

	// special power : Instead of attacking..
	us secondClick = 0;
	us key = 1;
};


#endif 
