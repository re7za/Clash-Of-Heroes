#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Button
{
public:
	Button();
	void draw(sf::RenderWindow* window);
	void onMouseOver();

	// sfml methodes
	void setFillColor(const sf::Color&);
	void setPosition(const sf::Vector2f&);
	void setCharacterSize(unsigned short size);
	void setString(const sf::String&);
	sf::FloatRect getGlobalBound();
	const sf::Vector2f& getPosition();
	unsigned short getCharacterSize();

	// rect
	void setRectSize(const sf::Vector2f&);
	void setRectColor(const sf::Color&);

private:
	sf::Font btnFont;
	sf::Text btnTxt;
	sf::RectangleShape btnRect;

	bool isClicked = false;
};

#endif // !1
