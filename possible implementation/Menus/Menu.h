#pragma once

#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "../Player/PlayerManager.h"
#include "../generalDef.h"

static class Menu
{
public:
	virtual ~Menu();

	virtual void display(sf::RenderWindow*) = 0;
	virtual void mouseHover(sf::RenderWindow*) = 0;
	virtual void click(sf::Vector2i&, menuType&) = 0;
	menuType getMenuName();
	menuType getPreviousMenu();

	// player manager
	//void playerDisplayManager(sf::RenderWindow*, PlayerManager*);
	void badSetPManager(PlayerManager*);
	PlayerManager* badGetPManager();


protected:
	void setGamelabel();
	
	menuType menuName;
	menuType previousMenu;

	// background
	sf::Texture backgroundTex;
	sf::Sprite menuSpr;
	sf::Font gameLabelFont;
	sf::Text gamelabel;
	
	// unfortunately have to define playerManager here.. for now
	PlayerManager* playerManager = new PlayerManager();

};

#endif