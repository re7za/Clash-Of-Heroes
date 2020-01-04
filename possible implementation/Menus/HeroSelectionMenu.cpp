#pragma once
#include <iostream>
#include "HeroSelectionMenu.h"

using namespace std;

HeroSelectionMenu::HeroSelectionMenu()
{
	menuName = menuType::heroSelection;
	previousMenu = menuType::mainMenu;

	// texture
	backgroundTex.loadFromFile("Menus/background/mainMenu.png");

	// sprite
	menuSpr.setTexture(backgroundTex);

	// label and font
	setGamelabel();
	gamelabel.setPosition(menuSpr.getGlobalBounds().left + 70,
		menuSpr.getGlobalBounds().height * 2 / 3);

	// back button
	backBtn.setString("back");
	backBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 150, 20));
}

void HeroSelectionMenu::display(sf::RenderWindow* window)
{
	mouseHover(window);

	window->draw(menuSpr);
	window->draw(gamelabel);
	backBtn.draw(window);
}

void HeroSelectionMenu::mouseHover(sf::RenderWindow* window)
{
	backBtn.onMouseOver();
}