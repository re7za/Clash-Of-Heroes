#pragma once

#ifndef KRATOSCARD_H
#define KRATOSCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class KratosCard : public HerosCard
{
public:
	KratosCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
