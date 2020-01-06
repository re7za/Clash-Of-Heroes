#pragma once

#ifndef HERODCARD_H
#define HEROSCARD_H

#include "SFML/Graphics.hpp"

class HerosCard
{
public:
	virtual void draw(sf::RenderWindow*) = 0;
	virtual void setCardSpr() = 0;
	void setColor(sf::Color);
	sf::Color getSprOrginalColor();
	
	void setCardName(std::string);
	std::string getCardName();
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBound();
	void setCardSelection(bool);
	bool isCardSelected();
	
protected:
	void setDefaulProperties();

	std::string cardName;

	sf::Texture heroCardTex;
	sf::Sprite heroCardSpr;
	// spr color
	sf::Color SprOrginalColor;

	sf::Font nameFont;
	sf::Font propertiFont;
	sf::Text heroNameTxt;
	sf::Text healthTxt;
	sf::Text damageTxt;

	bool cardSelection = false;

};

#endif