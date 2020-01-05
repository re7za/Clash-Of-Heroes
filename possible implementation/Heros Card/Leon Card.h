#pragma once

#ifndef LEONCARD_H
#define LEONCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class LeonCard : public HerosCard
{
public:
	LeonCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif