#pragma once

#ifndef COMMANDERCARD_H
#define COMMANDERCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class CommanderCard : public HerosCard
{
public:
	CommanderCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif
