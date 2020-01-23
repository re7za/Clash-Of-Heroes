#pragma once

#ifndef PROFESSORBATTLECARD_H
#define PROFESSORBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class ProfessorBattleCard : public BattleCard
{
public:
	ProfessorBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
