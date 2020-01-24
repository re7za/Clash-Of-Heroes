#pragma once

#ifndef BATTLECARDMANAGER_H
#define BATTLECARDMANAGER_H

enum class PlayerEnum {P1, P2};

#include <iostream>
#include "SFML/Graphics.hpp"
#include <array>
#include "BattleCard.h"
#include "AlphaManBattleCard.h"
#include "CommanderBattleCard.h"
#include "DrMarryBattleCard.h"
#include "GiantBattleCard.h"
#include "KratosBattleCard.h"
#include "LeonBattleCard.h"
#include "MrsGhostBattleCard.h"
#include "ProfessorBattleCard.h"
#include "RickKhonsariBattleCard.h"
#include "ROBIBattleCard.h"
#include "SniperBattleCard.h"
#include "SybilBattleCard.h"


class BattleCardManager
{
public:
	BattleCardManager();
	void drawHerosCard(sf::RenderWindow*);
	void clickHeroEachCard(const sf::Vector2i&);
	void hoverHeroEachCard(PlayerEnum);
	void turnIsChanged(PlayerEnum);

	// extract heroes from the playerHeroVec
	void heroExtracter(std::array<heros, 10>);

	// set cards positions
	void setGridsCardsPos(sf::Vector2f , sf::FloatRect);
	
	// card selection
	void setSelectedCard(heros);
	heros getSelectedCard();
	heros& getSelectedCardByRefrence();

private:

	std::array<BattleCard*, 5> leftCardArr;
	std::array<BattleCard*, 5> rightCardArr;

	// card selection
	heros selectedCard = heros::none;

};


#endif // !HEROCARDMANAGER_H
