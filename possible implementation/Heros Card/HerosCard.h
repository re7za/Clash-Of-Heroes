#pragma once

#ifndef HERODCARD_H
#define HEROSCARD_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"

class HerosCard
{
public:
	virtual ~HerosCard();

	virtual void draw(sf::RenderWindow*) = 0;
	virtual void setCardSpr() = 0;
	void setColor(sf::Color);
	sf::Color getSprOrginalColor();
	
	heros getCardName();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBound();


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

#endif