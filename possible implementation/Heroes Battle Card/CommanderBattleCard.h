#pragma once

#ifndef COMMANDERBATTLECARD_H
#define COMMANDERBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class CommanderBattleCard : public BattleCard
{
public:
	CommanderBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
