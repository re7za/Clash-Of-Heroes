#pragma once

#ifndef BATTLECARD_H
#define BATTLECARD_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"
#include <iostream>

class BattleCard
{
public:
	virtual ~BattleCard();

	virtual void draw(sf::RenderWindow*) = 0;
	virtual void setCardSpr() = 0;

	void setColor(sf::Color);
	void setPosition(sf::Vector2f);
	sf::Color getSprOrginalColor();
	void horizontalFlip();
	heros getCardName();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getHeroNamePos();


	// card selection
	void setCardSelection(bool);
	bool isCardSelected();

protected:
	void setDefaulProperties();

	bool cardSelection = false;

	heros cardName;

	sf::Texture heroCardTex;
	sf::Sprite heroCardSpr;
	// spr color
	sf::Color SprOrginalColor;

	sf::Font nameFont;
	sf::Font propertiFont;
	sf::Text heroNameTxt;
	sf::Text healthTxt;
	sf::Text damageTxt;
};



#endif // !
