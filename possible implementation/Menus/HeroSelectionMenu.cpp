#pragma once
#include "HeroSelectionMenu.h"

using namespace std;

HeroSelectionMenu::HeroSelectionMenu()
{
	// set the name and others
	menuName = menuType::heroSelection;
	previousMenu = menuType::mainMenu;

	// texture
	backgroundTex.loadFromFile("Menus/background/MainMenu.jpg");
	// sprite
	menuSpr.setTexture(backgroundTex);

	// label and font
	setGamelabel();
	gamelabel.setPosition(menuSpr.getGlobalBounds().left + 70,
		menuSpr.getGlobalBounds().height * 2 / 3);
	
	// selection grid
	grid.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 + 100,
		sf::VideoMode::getDesktopMode().height * 1 / 3 - 30));

	//////////// back button.. nameBox and...
	// back button
	backBtn.setString("back");
	backBtn.setCharacterSize(60);
	backBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 180, 10));
	// next button
	nextBtn.setString("done");
	nextBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 180, 80));

	// name box
	nameRect.setFillColor(sf::Color(20, 20, 20, 200));
	nameRect.setSize(sf::Vector2f(nameRectWidth, nameRectHeight));
	nameRect.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setCharacterSize(37);
	nameBox.setPosition(sf::Vector2f(nameRectLeft, nameRectTop));
	nameBox.setSelected(false);
	//nameBox.setString("player 1");

	// name input label
	nameInputLabelRect.setFillColor(sf::Color(5, 5, 5, 200));
	nameInputLabelRect.setSize(sf::Vector2f(nameRectWidth , nameRectHeight));
	nameInputLabelRect.setPosition(sf::Vector2f(nameRectLeft - nameRectWidth, nameRectTop));
	if (!nameInputLabelFont.loadFromFile("Font/Button.otf"))
		std::cout << "nameInputLabelFont doesn't open" << std::endl;
	nameInputLabelText.setString("     Hero 1 :");
	nameInputLabelText.setCharacterSize(38);
	nameInputLabelText.setFont(nameInputLabelFont);
	nameInputLabelText.setFillColor(sf::Color::White);
	nameInputLabelText.setPosition(sf::Vector2f(nameInputLabelRect.getPosition().x + 25,
		nameInputLabelRect.getPosition().y + 10));	


}

void HeroSelectionMenu::display(sf::RenderWindow* window)
{
	window->draw(menuSpr);
	////////////////////// and the other
	window->draw(gamelabel);
	backBtn.draw(window);
	nextBtn.draw(window);
	mouseHover(window);

	// input name
	window->draw(nameRect);
	window->draw(nameInputLabelRect);
	window->draw(nameInputLabelText);
	window->draw(nameRect);
	//nameBox.draw(window);

	// hreos card
	heroCardManager.drawHerosCard(window);

	// grid
	grid.draw(window);
}

// mouse events and positions
void HeroSelectionMenu::click(sf::Vector2i& pos, menuType& currentMenu)
{
	// grid.. it must be before the herocard part
	if (grid.getGlobalBound().contains(sf::Vector2f(pos)))
		grid.SelectionClicked(pos, playerManager, heroCardManager.getSelectedCardByRefrence());

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
	// backButton
	if (backBtn.getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
	{
		// just for now
		resetSelectionMenuInformation();
		currentMenu = menuType::mainMenu;
	}

	// nextButton
	if (nextBtn.getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
	{
		//currentMenu = menuType::battlefield;
		if (playerManager->getTheTurn() == Players::P1)
		{
			if (playerManager->playerArr.at(0)->isPlayerHeroVecFull())
			{
				grid.clearAllTiles();
				nextBtn.setString("start");
				nameInputLabelText.setString("     Hero 2 :");
				nameBox.setString("Player 2");

				// at last
				playerManager->changeTheTurn();
			}
			else
			{
				//std::cout << "u have to choose more" << std::endl;
			}
		}
		else if (playerManager->getTheTurn() == Players::P2)
		{
			if (playerManager->playerArr.at(1)->isPlayerHeroVecFull())
			{
				// save the chosen heroes
				playerManager->setTheChosenHeroes();
				//playerManager->clearTheCHosenHeroes();

				// at last
				playerManager->changeTheTurn();
				grid.clearAllTiles();
				currentMenu = menuType::battlefield;
			}
			else
			{
				//std::cout << "u have to choose more" << std::endl;
			}
		}
	}
}

// utility functions of mouse envents and positions
void HeroSelectionMenu::mouseHover(sf::RenderWindow* window)
{
	backBtn.onMouseOver();
	nextBtn.onMouseOver();

	// cards
	heroCardManager.hoverHeroEachCard();
}

void HeroSelectionMenu::resetSelectionMenuInformation()
{
	// player's heroes
	playerManager->clearPlayerMemory();
	playerManager->clearheChosenHeroes();

	// grid
	grid.clearAllTiles();

	// next button
	nextBtn.setString("done");

	// player turn
	if (playerManager->getTheTurn() == Players::P2)
		playerManager->changeTheTurn();

	if (playerManager->getTheTurn() == Players::P1)
		nameInputLabelText.setString("     Hero 1 :");

}
