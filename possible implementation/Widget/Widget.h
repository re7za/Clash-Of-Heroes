#pragma once

#ifndef WIDGET_H
#define WIDGET_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "../Button/Button.h"

class Widget
{
public:
	Widget();
	Widget(const std::string& str);
	Widget(const std::string& str1, const std::string& str2);
	Widget(const std::string& str1, const std::string& str2, const std::string& str3);

	void draw(sf::RenderWindow*);
	void onMouseHover();

	// message sfml functions
	void setMessageColor(const sf::Color&);
	void setMessageString(const std::string&);
	void setMessagePosition(const sf::Vector2f&);
	void setMessageCharacterSize(const unsigned short&);

	bool isClicked(const sf::Vector2f& pos);
	void clicked(const sf::Vector2f&);
	
	// buttons
	std::vector <Button*> buttonVec;

	// widget activation
	bool activation = false;
private:
	
	// bsckground
	sf::RectangleShape backgroundRect;
	sf::RectangleShape messageRect;

	// message
	sf::Font messageFont;
	sf::Text messageTxt;

};


#endif // !WIDGET
