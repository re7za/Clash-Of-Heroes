#pragma once

#ifndef SNIPERBATTLECARD_H
#define SNIPERBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class SniperBattleCard : public BattleCard
{
public:
	SniperBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
