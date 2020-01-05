#pragma once

#ifndef SNIPERCARD_H
#define SNIPERCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class SniperCard : public HerosCard
{
public:
	SniperCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
