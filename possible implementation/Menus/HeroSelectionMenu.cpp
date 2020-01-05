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

	// name box
	nameRect.setFillColor(sf::Color(20, 20, 20, 200));
	nameRect.setSize(sf::Vector2f(nameRectWidth, nameRectHeight));
	nameRect.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setCharacterSize(37);
	nameBox.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setSelected(false);

	// name input label
	nameInputLabelRect.setFillColor(sf::Color(5, 5, 5, 200));
	nameInputLabelRect.setSize(sf::Vector2f(nameRectWidth , nameRectHeight));
	nameInputLabelRect.setPosition(sf::Vector2f(nameRectLeft - nameRectWidth, nameRectTop));
	if (!nameInputLabelFont.loadFromFile("Font/Button.otf"))
		std::cout << "fuuuuuuuuck" << std::endl;
	
	nameInputLabelText.setString("Enter your name");
	nameInputLabelText.setCharacterSize(38);
	nameInputLabelText.setFont(nameInputLabelFont);
	nameInputLabelText.setFillColor(sf::Color::White);
	nameInputLabelText.setPosition(sf::Vector2f(nameInputLabelRect.getPosition().x + 25,
		nameInputLabelRect.getPosition().y + 10));

	
}

void HeroSelectionMenu::display(sf::RenderWindow* window)
{
	window->draw(menuSpr);
	//////////////////////
	window->draw(gamelabel);
	backBtn.draw(window);
	mouseHover(window);

	// input name
	window->draw(nameRect);
	window->draw(nameInputLabelRect);
	window->draw(nameInputLabelText);
	window->draw(nameRect);

	// hreos card
	drawHerosCard(window);
}

void HeroSelectionMenu::mouseHover(sf::RenderWindow* window)
{
	backBtn.onMouseOver();
}

void HeroSelectionMenu::rightClick(sf::Vector2i pos)
{
	if (pos.x >= nameRectLeft - nameRectWidth && pos.x <= nameRectLeft + nameRectWidth
		&& pos.y >= nameRectTop && pos.y <= nameRectTop + nameRectHeight)
	{
		if (!nameBox.isItSelected())
		{
			nameRect.setFillColor(sf::Color(50, 50, 50, 230));
			nameBox.setSelected(true);
		}
	}
	else
	{
		if (nameBox.isItSelected())
		{
			nameRect.setFillColor(sf::Color(20, 20, 20, 200));
			nameBox.setSelected(false);
		}
	}
}

void HeroSelectionMenu::drawHerosCard(sf::RenderWindow* window)
{
	alphaManCard.draw(window);
	commanderCard.draw(window);
	drMarryCard.draw(window);
	giantCard.draw(window);
	kratosCard.draw(window);
	leonCard.draw(window);
	mrsGhostCard.draw(window);
	professorCard.draw(window);
	rickKhonsariCard.draw(window);
	ROBICard.draw(window);
	sniperCard.draw(window);
	sybilCard.draw(window);
}