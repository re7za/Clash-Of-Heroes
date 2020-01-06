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

	// push_back in heroCard
	heroCardVec.push_back(&alphaManCard);
	heroCardVec.push_back(&commanderCard);
	heroCardVec.push_back(&drMarryCard);
	heroCardVec.push_back(&giantCard);
	heroCardVec.push_back(&kratosCard);
	heroCardVec.push_back(&leonCard);
	heroCardVec.push_back(&mrsGhostCard);
	heroCardVec.push_back(&professorCard);
	heroCardVec.push_back(&rickKhonsariCard);
	heroCardVec.push_back(&ROBICard);
	heroCardVec.push_back(&sniperCard);
	heroCardVec.push_back(&sybilCard);
	
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
	// back button
	rightClickBackBtn(pos);

	// each hero card
	rightClickHeroEachCard(pos);
}

void HeroSelectionMenu::rightClickBackBtn(sf::Vector2i pos)
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

void HeroSelectionMenu::rightClickHeroEachCard(sf::Vector2i pos)
{
	for (HerosCard* card : heroCardVec)
		if (pos.x >=  card->getGlobalBound().left && pos.x <= card->getPosition().x + 150
			&& pos.y >= card->getGlobalBound().top && pos.y <= card->getPosition().y + 230)
		{
			if (!card->isCardSelected())
			{
				card->setCardSelection(true);
				card->setColor(sf::Color(card->getSprOrginalColor().r + 40, card->getSprOrginalColor().g + 20,
					card->getSprOrginalColor().b + 20, 255));
			}
		}
		else
		{
			if (card->isCardSelected())
			{
				card->setCardSelection(false);
				card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
					card->getSprOrginalColor().b, 255));
			}
		}
} 

void HeroSelectionMenu::drawHerosCard(sf::RenderWindow* window)
{
	for (HerosCard* card : heroCardVec)
		card->draw(window);
		
}