#pragma once
#pragma once

#ifndef KRATOSBATTLECARD_H
#define KRATOSBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class KratosBattleCard : public BattleCard
{
public:
	KratosBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

	void anotherClick();
	us getTheClickSituation();
	void resetTheClickSituation();

private:

	// special power : Instead of attacking.. replace one of his heroes
	us secondClick = 0;

};


#endif 
