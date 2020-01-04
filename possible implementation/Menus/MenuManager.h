
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "HeroSelectionMenu.h"
#include "../generalDef.h"
#include <vector>

class MenuManager
{
public:
	MenuManager();
	void displayCurrentMenu(sf::RenderWindow*);
	//static void returnToPreviousMenu();

	menuType getCurrentMenu();
	void setCurrentMenu(menuType);
	void rightClickPos(sf::Vector2i);

private:
	menuType currentMenu;
	std::vector <Menu*> menuVec;
	HeroSelectionMenu heroSelectionMenu;
};


#endif