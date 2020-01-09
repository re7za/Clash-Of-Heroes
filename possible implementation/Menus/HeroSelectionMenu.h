#pragma once

#ifndef HEROSELECTIONMENU_H
#define HEROSELECTIONMENU_H

#include "Menu.h"
#include "../Heros Card/HeroCardManager.h"
#include "../Grid/Grid.h"
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

	// mouse events and positions
	//void mousePosition(sf::Vector2i&);
	void rightClick(sf::Vector2i&);

	// utility functions of mouse envents and positions
	void mouseHover(sf::RenderWindow*);
	void rightClickBackBtn(sf::Vector2i&);


private:

	// HeroCardManager
	HeroCardManager heroCardManager;

	// menu grid
	Grid grid;

	// another bullShits
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