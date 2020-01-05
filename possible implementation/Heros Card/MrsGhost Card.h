#pragma once

#ifndef MRSGHOSTCARD_H
#define MRSGHOSTCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class MrsGhostCard : public HerosCard
{
public:
	MrsGhostCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
