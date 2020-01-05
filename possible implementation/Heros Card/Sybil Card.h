#pragma once

#ifndef SYBILCARD_H
#define SYBILCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class SybilCard : public HerosCard
{
public:
	SybilCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
