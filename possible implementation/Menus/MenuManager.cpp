
#include <iostream>
#include "MenuManager.h"

using namespace std;

MenuManager::MenuManager()
{
	currentMenu = menuType::heroSelection;	// for now
	_currentMenu = currentMenu;
	menuVec.push_back(&heroSelectionMenu);
	menuVec.push_back(&battlefield);
}

void MenuManager::clickPos(sf::Vector2i pos)
{
	for (Menu* menu : menuVec)
		if (menu->getMenuName() == currentMenu)
		{
			menu->click(pos, currentMenu);
			break;
		}

	// update the _currentMenu
	if (_currentMenu == menuType::heroSelection
		&& currentMenu == menuType::battlefield)
	{
		battlefield.badSetPManager(heroSelectionMenu.badGetPManager());
		_currentMenu = currentMenu;
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
