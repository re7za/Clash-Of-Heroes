#pragma once
#pragma once

#ifndef RICKKHONSARICARD_H
#define RICKKHONSARICARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class RickKhonsariCard : public HerosCard
{
public:
	RickKhonsariCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
