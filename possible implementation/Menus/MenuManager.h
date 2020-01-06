
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "HeroSelectionMenu.h"
#include "../Player/PlayerManager.h"
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

	// events and positions
	void getMousePosition(sf::Vector2i);
	void rightClickPos(sf::Vector2i);

private:
	menuType currentMenu;
	std::vector <Menu*> menuVec;
	HeroSelectionMenu heroSelectionMenu;

	// each player plays in menu actually
	PlayerManager playerManager;	// نباید توی منو ها تعریف بشه چون برای هر منو یدونه ساخته میشه

};


#endif