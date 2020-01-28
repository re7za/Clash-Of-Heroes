#pragma once

#ifndef PANEL_H
#define PANEL_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"

class Panel
{
public:
	Panel();
	Panel(std::string str, us characterSize);

	void draw(sf::RenderWindow*);
	
	// sfml text function
	// setter
	void setCharacterSize(const us&);
	void setFillColor(const sf::Color&);
	void setFont(const sf::Font&);
	void setOutlineColor(const sf::Color&);
	void setOutlineThinkness(float thinkness);
	void setPosition(const sf::Vector2f&);
	void setString(const std::string&);
	void setStyle(sf::Uint32 style);
	// getter
	us getCharacterSize();
	sf::Color getFillColor();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();

	void setOrginalFillColor(const sf::Color&);
	sf::Color getOrginalFillColor();


private:
	
	// background Sprite
	sf::RectangleShape rect;

	// text
	sf::Font txtFont;
	sf::Text txt;

	sf::Color orginalColor;

};

#endif // !PANEL_H
