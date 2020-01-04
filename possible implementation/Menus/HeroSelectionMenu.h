#pragma once

#ifndef HEROSELECTIONMENU_H
#define HEROSELECTIONMENU_H

#include "Menu.h"
#include "../Button/Button.h"
#include "../Textbox/Textbox.h"

#define nameRectLeft sf::VideoMode::getDesktopMode().width / 2 + 450
#define nameRectHeight 70
#define nameRectWidth 330
#define nameRectTop 220

class HeroSelectionMenu : public Menu
{
public:
	HeroSelectionMenu();
	void display(sf::RenderWindow*);
	void mouseHover(sf::RenderWindow*);
	void rightClick(sf::Vector2i);

private:
	Button backBtn;

	// nameBox
	Textbox nameBox;
	sf::RectangleShape nameRect;

	// name input label
	sf::RectangleShape nameInputLabelRect;
	sf::Font nameInputLabelFont;
	sf::Text nameInputLabelText;
	
};


#endif