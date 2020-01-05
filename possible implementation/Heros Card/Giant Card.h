#pragma once

#ifndef GIANTCARD_H
#define GIANTCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class GiantCard : public HerosCard
{
public:
	GiantCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif
