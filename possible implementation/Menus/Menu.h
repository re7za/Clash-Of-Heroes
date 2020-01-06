#pragma once

#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"

static class Menu
{
public:
	virtual void display(sf::RenderWindow*) = 0;
	virtual void mouseHover(sf::RenderWindow*) = 0;
	virtual void mousePosition(sf::Vector2i) = 0;
	virtual void rightClick(sf::Vector2i) = 0;
	menuType getMenuName();
	menuType getPreviousMenu();

protected:
	void setGamelabel();
	
	menuType menuName;
	menuType previousMenu;

	// background
	sf::Texture backgroundTex;
	sf::Sprite menuSpr;
	sf::Font gameLabelFont;
	sf::Text gamelabel;
	
};

#endif