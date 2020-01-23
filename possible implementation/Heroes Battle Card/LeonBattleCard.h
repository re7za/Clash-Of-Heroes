#pragma once

#ifndef LEONBATTLECARD_H
#define LEONBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class LeonBattleCard : public BattleCard
{
public:
	LeonBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
