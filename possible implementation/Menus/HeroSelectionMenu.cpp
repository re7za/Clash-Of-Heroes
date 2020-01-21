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
	
	// grid
	grid.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 + 100,
		sf::VideoMode::getDesktopMode().height * 1 / 3 - 30));

	//////////// back button.. nameBox and...
	// back button
	backBtn.setString("back");
	backBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 150, 20));
	// next button
	nextBtn.setString("done");
	nextBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 150, 90));

	// name box
	nameRect.setFillColor(sf::Color(20, 20, 20, 200));
	nameRect.setSize(sf::Vector2f(nameRectWidth, nameRectHeight));
	nameRect.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setCharacterSize(37);
	nameBox.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setSelected(false);
	nameBox.setString("player 1");

	// name input label
	nameInputLabelRect.setFillColor(sf::Color(5, 5, 5, 200));
	nameInputLabelRect.setSize(sf::Vector2f(nameRectWidth , nameRectHeight));
	nameInputLabelRect.setPosition(sf::Vector2f(nameRectLeft - nameRectWidth, nameRectTop));
	if (!nameInputLabelFont.loadFromFile("Font/Button.otf"))
		std::cout << "nameInputLabelFont doesn't open" << std::endl;
	nameInputLabelText.setString("enter your name :");
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
	nextBtn.draw(window);
	mouseHover(window);

	// input name
	window->draw(nameRect);
	window->draw(nameInputLabelRect);
	window->draw(nameInputLabelText);
	window->draw(nameRect);

	// hreos card
	heroCardManager.drawHerosCard(window);

	// grid
	grid.draw(window);
}

// mouse events and positions
void HeroSelectionMenu::click(sf::Vector2i& pos, menuType& currentMenu)
{
	// grid.. it must be before the herocard part
	grid.gridClicked(pos, playerManager, heroCardManager.getSelectedCardByRefrence());

	// each hero card
	heroCardManager.clickHeroEachCard(pos);

	// name box
	//clickNameBox(pos);
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

	//////// buttons
	/* backButton
	if (pos.x > backBtn.getGlobalBound().left
		&& pos.x < backBtn.getGlobalBound().left + backBtn.getGlobalBound().width
		&& pos.y > backBtn.getGlobalBound().top
		&& pos.y < backBtn.getGlobalBound().top + backBtn.getGlobalBound().height)
		// هر کاری ک باید برای دکمه بک باشه
		*/
		// nextButton
	if (nextBtn.getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
	{
		if (playerManager.getTheTurn() == Players::P1)
		{
			std::cout << static_cast<int> (playerManager.getTheTurn()) << std::endl;
			if (playerManager.playerArr.at(0)->isPlayerHeroVecFull())
			{
				grid.clearAllTiles();
				nextBtn.setString("start");
				nameBox.setString("Player 2");

				// at last
				playerManager.changeTheTurn();

			}
			else
			{
				std::cout << "u have to choose more" << std::endl;
			}
		}
		else
		{
			std::cout << static_cast<int> (playerManager.getTheTurn()) << std::endl;
			if (playerManager.playerArr.at(0)->isPlayerHeroVecFull())
			{
				/*grid.clearAllTiles();
				for (Hero* i : playerManager.playerArr.at(0)->playerHerosVec)
					std::cout << i->getId() << "    ";
				std::cout << std::endl;
				for (Hero* i : playerManager.playerArr.at(1)->playerHerosVec)
					std::cout << i->getId() << "    ";
				std::cout << std::endl << std::endl;*/
			}
			else
			{
				std::cout << "u have to choose more" << std::endl;
			}

			// at last
			// currentMenu = menuType::PlayRoom Menu;
		}
	}
}

/*	// هزینه صدا زدن هر تابع بیشتر از پایین اومدن خوانایی کده
void HeroSelectionMenu::clickNameBox(sf::Vector2i& pos)
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
*/

// utility functions of mouse envents and positions
void HeroSelectionMenu::mouseHover(sf::RenderWindow* window)
{
	backBtn.onMouseOver();
	nextBtn.onMouseOver();
}
