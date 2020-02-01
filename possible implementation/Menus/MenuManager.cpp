
#include "MenuManager.h"

using namespace std;

MenuManager::MenuManager()
{
	currentMenu = menuType::heroSelection;	// for now
	_currentMenu = currentMenu;
	menuVec.push_back(&heroSelectionMenu);
	menuVec.push_back(&battlefield);
	menuVec.push_back(&mainMenu);
}

void MenuManager::clickPos(sf::Vector2i pos)
{
	for (Menu* menu : menuVec)
		if (menu->getMenuName() == currentMenu)
		{
			menu->click(pos, currentMenu);
			break;
		}

	// switch from main menu to selection menu
	if (_currentMenu == menuType::mainMenu
		&& currentMenu == menuType::heroSelection)
	{
		_currentMenu = currentMenu;
	}

	// switch from selection menu to battlefield
	if (_currentMenu == menuType::heroSelection
		&& currentMenu == menuType::battlefield)
	{
		// copy the playerManager Address
		battlefield.badSetPManager(heroSelectionMenu.badGetPManager());
		
		//////////////// and also playermanager.heroExtracter() was changed and battlefield constructor and line 28 was commented

		battlefield.startTheBattlefield();
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
