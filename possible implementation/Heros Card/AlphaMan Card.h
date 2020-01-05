#pragma once

#ifndef ALPHAMANCARD_H
#define ALPHAMANCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class AlphaManCard : public HerosCard
{
public:
	AlphaManCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);
	
private:

};


#endif 
