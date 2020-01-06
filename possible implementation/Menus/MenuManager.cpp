
#include <iostream>
#include "MenuManager.h"

using namespace std;

MenuManager::MenuManager()
{
	currentMenu = menuType::heroSelection;	// for now
	menuVec.push_back(&heroSelectionMenu);
}

void MenuManager::getMousePosition(sf::Vector2i pos)
{
	for (Menu* menu : menuVec)
		if (menu->getMenuName() == currentMenu)
		{
			menu->mousePosition(pos);
			break;
		}
}
void MenuManager::rightClickPos(sf::Vector2i pos)
{
	for (Menu* menu : menuVec)
		if (menu->getMenuName() == currentMenu)
		{
			menu->rightClick(pos);
			break;
		}
}


void MenuManager::displayCurrentMenu(sf::RenderWindow* window)
{
	// frame refreshing
	// which menu?
	for (Menu* menu : menuVec)
		if (menu->getMenuName() == currentMenu)
		{
			menu->display(window);
			break;
		}
}

menuType MenuManager::getCurrentMenu()
{
	return currentMenu;
}

void MenuManager::setCurrentMenu(menuType newCurrentMenu)
{
	currentMenu = newCurrentMenu;
}
