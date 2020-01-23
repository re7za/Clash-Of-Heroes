#pragma once

#ifndef SYBILBATTLECARD_H
#define SYBILBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class SybilBattleCard : public BattleCard
{
public:
	SybilBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
