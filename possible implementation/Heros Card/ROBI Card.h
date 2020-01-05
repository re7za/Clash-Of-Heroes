#pragma once

#ifndef ROBICARD_H
#define ROBICARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class ROBICard : public HerosCard
{
public:
	ROBICard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
