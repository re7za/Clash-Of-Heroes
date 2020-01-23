#pragma once

#ifndef ROBIBATTLECARD_H
#define ROBIBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class ROBIBattleCard : public BattleCard
{
public:
	ROBIBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
