#pragma once

#ifndef HEROCARDMANAGER_H
#define HEROCARDMANAGER_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "../Heros Card/HerosCard.h"
#include "../Heros Card/AlphaMan Card.h"
#include "../Heros Card/Commander Card.h"
#include "../Heros Card/DrMarry Card.h"
#include "../Heros Card/Giant Card.h"
#include "../Heros Card/Kratos Card.h"
#include "../Heros Card/Leon Card.h"
#include "../Heros Card/MrsGhost Card.h"
#include "../Heros Card/Professor Card.h"
#include "../Heros Card/RickKhonsari Card.h"
#include "../Heros Card/ROBI Card.h"
#include "../Heros Card/Sniper Card.h"
#include "../Heros Card/Sybil Card.h"

class HeroCardManager
{
public:
	HeroCardManager();
	void drawHerosCard(sf::RenderWindow*);
	void rightClickHeroEachCard(sf::Vector2i& pos);

	// card selection
	void setSelectedCard(heros);
	heros getSelectedCard();
	heros& getSelectedCardByRefrence();

private:

	std::vector<HerosCard*> heroCardVec;

	// card selection
	heros selectedCard = heros::none;

	// fucking hero cards
	AlphaManCard alphaManCard;
	CommanderCard commanderCard;
	DrMarryCard drMarryCard;
	GiantCard giantCard;
	KratosCard kratosCard;
	LeonCard leonCard;
	MrsGhostCard mrsGhostCard;
	ProfessorCard professorCard;
	RickKhonsariCard rickKhonsariCard;
	ROBICard ROBICard;
	SniperCard sniperCard;
	SybilCard sybilCard;
};


#endif // !HEROCARDMANAGER_H
