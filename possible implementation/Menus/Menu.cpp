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
	gamelabel.setFillColor(sf::Color(180, 33, 51, 220));
	gamelabel.setCharacterSize(100);
	gamelabel.setOutlineThickness(4);
	gamelabel.setOutlineColor(sf::Color(20, 20, 20, 255));
}

// player manager
/*void Menu::playerDisplayManager(sf::RenderWindow* window, PlayerManager& playerManager)
{
	playerManager.displayPlayerInfo(window);
}*/