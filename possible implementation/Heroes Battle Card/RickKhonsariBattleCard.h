#pragma once

#ifndef RickKhonsariBATTLECARD_H
#define RickKhonsariBATTLECARD_H

#include "SFML/Graphics.hpp"
#include "BattleCard.h"

class RickKhonsariBattleCard : public BattleCard
{
public:
	RickKhonsariBattleCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
