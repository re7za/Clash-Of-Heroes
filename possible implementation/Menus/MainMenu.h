#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include "../generalDef.h"
#include "Menu.h"
#include "../Button/Button.h"

class MainMenu : public Menu
{
public:
	MainMenu();

	void display(sf::RenderWindow*);
	void mouseHover(sf::RenderWindow*);
	void click(sf::Vector2i&, menuType&);

	
private:
	
	// strip
	sf::Texture stripTex;
	sf::Sprite stripSpr;

	// buttons
	sf::Font font;
	Button startBtn;
	Button aboutBtn;
	Button quitBtn;

	// clash of heroes logo
	sf::Text clash;
	sf::Text of;
	sf::Text heroes;

	// window.. just for quit
	sf::RenderWindow* window;

};

#endif // !MAINMENU
