#pragma once

#ifndef HERODCARD_H
#define HEROSCARD_H

#include "SFML/Graphics.hpp"

class HerosCard
{
	virtual void draw(sf::RenderWindow*) = 0;
	virtual void setCardSpr() = 0;
	void setCardName(std::string);
	std::string getCardName();
	
protected:
	void setDefaulProperties();

	std::string cardName;

	sf::Texture heroCardTex;
	sf::Sprite heroCardSpr;

	sf::Font nameFont;
	sf::Font propertiFont;
	sf::Text heroNameTxt;
	sf::Text healthTxt;
	sf::Text damageTxt;

};

#endif