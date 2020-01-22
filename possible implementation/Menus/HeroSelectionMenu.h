#pragma once

#ifndef HEROSELECTIONMENU_H
#define HEROSELECTIONMENU_H

#include "../generalDef.h"
#include "Menu.h"
#include "../Heros Card/HeroCardManager.h"
#include "../Heros Card/HerosCard.h"
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

	////////////////////// mouse events and positions
	void click(sf::Vector2i&, menuType&);

	// clicking on the nameBox
	//void clickNameBox(sf::Vector2i&);

	// utility functions of mouse envents and positions
	void mouseHover(sf::RenderWindow*);


private:

	// HeroCardManager
	HeroCardManager heroCardManager;

	// selection grid
	Grid grid;

	// another bullShits
	Button backBtn;
	Button nextBtn;		// for this menu its "done" at first for P1 and then it changes to "start"

	// nameBox
	Textbox nameBox;
	sf::RectangleShape nameRect;

	// name input label
	sf::RectangleShape nameInputLabelRect;
	sf::Font nameInputLabelFont;
	sf::Text nameInputLabelText;
	
};


#endif