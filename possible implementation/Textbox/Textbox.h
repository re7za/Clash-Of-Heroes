#pragma once

#ifndef TASKBAR_H
#define TSDKBSR_H

#include <iostream>
#include <sstream>
#include "SFML/Graphics.hpp"
#include "../generalDef.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
public:
	Textbox();
	Textbox(us, bool);

	void setFont(sf::Font&);
	void setPosition(sf::Vector2f);
	void setLimit(bool);
	void setLimit(bool, int);
	void setSelected(bool);
	bool isItSelected();
	void setFillColor(sf::Color);
	void setCharacterSize(us);
	void setString(const std::string&);
	std::string getText();
	void draw(sf::RenderWindow*);
	void typedOn(sf::Event);


private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	us limit;

	void inputLogic(int);
	void deleteLastChar();
};

#endif // !TASKBAR_H
