#pragma once

#ifndef PROFESSORCARD_H
#define PROFESSORCARD_H

#include "SFML/Graphics.hpp"
#include "HerosCard.h"

class ProfessorCard : public HerosCard
{
public:
	ProfessorCard();
	void setCardSpr();
	void draw(sf::RenderWindow*);

private:

};


#endif 
