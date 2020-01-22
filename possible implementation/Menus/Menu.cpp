#pragma once
#include "Menu.h"

Menu::~Menu()
{
}

menuType Menu::getMenuName()
{
	return menuName;
}
menuType Menu::getPreviousMenu()
{
	return previousMenu;
}
void Menu::badSetPManager(PlayerManager* PManager)
{
	playerManager = PManager;
}
PlayerManager* Menu::badGetPManager()
{
	return playerManager;
}
void Menu::setGamelabel()
{
	gameLabelFont.loadFromFile("Font/fighting spirit TBS_bold.ttf");
	gamelabel.setFont(gameLabelFont);
	gamelabel.setString("     Clash Of\nHeroes");
	gamelabel.setFillColor(sf::Color(255, 255, 255, 220));
	gamelabel.setCharacterSize(100);
}

// player manager
/*void Menu::playerDisplayManager(sf::RenderWindow* window, PlayerManager& playerManager)
{
	playerManager.displayPlayerInfo(window);
}*/