#pragma once

#ifndef DRMARRYCARD_H
#define DRMARRYCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class DrMarryCard : public HerosCard
{
public:
	DrMarryCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif
