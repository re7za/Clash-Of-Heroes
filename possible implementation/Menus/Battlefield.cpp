#include "Battlefield.h"
#include <iostream>

Battlefield::Battlefield()
{
	// set the name and others
	menuName = menuType::battlefield;
	previousMenu = menuType::heroSelection;

	// texture and sprite
	changeBackground();

	// battle grid
	grid.setScale(sf::Vector2f(1.2f, 1.2f));
	grid.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width * 1/2,
		sf::VideoMode::getDesktopMode().height * 1 / 5));
	grid.setPosition(sf::Vector2f(grid.getPosition().x
		- grid.getGridSpr().getTextureRect().width 
		* grid.getScale().x / 2, grid.getPosition().y));
	grid.setFillColor(sf::Color(grid.getColor().r, grid.getColor().g, grid.getColor().b, 255));

	//pause button
	pauseBtn.setString("pause");
	pauseBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 150, 20));


	//////////////// test
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new AlphaMan(sf::Vector2i(3, 5)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Kratos(sf::Vector2i(2, 6)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Giant(sf::Vector2i(6, 4)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new MrsGhost(sf::Vector2i(5, 7)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Professor(sf::Vector2i(7, 1)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Sybil(sf::Vector2i(4, 2)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Sniper(sf::Vector2i(3, 8)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new ROBI(sf::Vector2i(1, 6)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Leon(sf::Vector2i(4, 4)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new DrMarry(sf::Vector2i(6, 7)));
	//////////////////////
	//
	startTheBattlefield();
}

void Battlefield::display(sf::RenderWindow* window)
{
	window->draw(menuSpr);
	////////////////////// and the other
	// button
	pauseBtn.draw(window);
	mouseHover(window);

	// battle grid
	grid.draw(window);

	// battle cards
	battleCardManager.drawHerosCard(window);
}

/////// mouse events and positions
void Battlefield::click(sf::Vector2i& pos, menuType& currentMenu)
{
	// grid and check for turn changing =)))))))))))
	bool isTurnChange = false;
	if (grid.getGlobalBound().contains(sf::Vector2f(pos)) && battleCardManager.getSelectedCard() != heros::none)
		grid.battlefieldClicked(pos, playerManager, isTurnChange);

	if (isTurnChange)
	{
		// attack prossecc by player.attackedPlayer and battleCard.selectedCard =))
		attackProcess();

		// changing the turn.. it must be after attack process
		playerManager->changeTheTurn();
		turnWasChanged(playerManager->getTheTurn());
	}

	// cards
	battleCardManager.clickHeroEachCard(pos, static_cast<PlayerEnum>(playerManager->getTheTurn()));
}

void Battlefield::mouseHover(sf::RenderWindow*)
{	
	pauseBtn.onMouseOver();

	// cards
	battleCardManager.hoverHeroEachCard(static_cast<PlayerEnum>(playerManager->getTheTurn()));
}
//////////////////////////////////

// background img
void Battlefield::startTheBattlefield()
{
	// at first.. extract the chosenHeroes
	battleCardManager.heroExtracter(playerManager->getTheChosenHeroes());

	// and then set the cards position
	battleCardManager.setGridsCardsPos(grid.getPosition(), grid.getGlobalBound());

	// planting the hero in the grid=
	turnWasChanged(playerManager->getTheTurn());
}

void Battlefield::turnWasChanged(Players playerTurn)
{
	// changing the cards
	battleCardManager.turnWasChanged(static_cast<PlayerEnum>(playerTurn));

	// attackedHero must set to none before next attack.. and 'don't change the index'!
	playerManager->playerArr.at(static_cast<us>(playerManager->getTheTurn()))->attackedHero = heros::none;
	playerManager->playerArr.at(static_cast<us>(playerManager->getAttackedPlayer()))->attackedHero = heros::none;

	// planting new heroes
	if (playerTurn == Players::P1)
		grid.plantingHeroes(playerManager->playerArr.at(static_cast<us>(Players::P2))->playerHerosVec);
	else
		grid.plantingHeroes(playerManager->playerArr.at(static_cast<us>(Players::P1))->playerHerosVec);

}

void Battlefield::attackProcess()
{
	// variables check
		//don't delete this comment
	std::cout << "get the turn              : " << static_cast <int> (playerManager->getTheTurn()) << std::endl;
	std::cout << "get attacked player       : " << static_cast <int> (playerManager->getAttackedPlayer()) << std::endl;
	std::cout << "selected card (attacher)  : " << static_cast <int> (battleCardManager.getSelectedCard()) << std::endl;
	std::cout << "attacked Hero             : " << static_cast <int> (playerManager->playerArr
		.at(static_cast <int> (playerManager->getAttackedPlayer()))->attackedHero) << std::endl;
	std::cout << "//////////////////////////////////" << std::endl;


	// start the war
	if (playerManager->playerArr.at(static_cast<us>(playerManager->getAttackedPlayer()))->attackedHero != heros::none)
		for (Hero* attackerHero : playerManager->playerArr.at(static_cast<us>(playerManager->getTheTurn()))->playerHerosVec)
			if (attackerHero->getId() == battleCardManager.getSelectedCard())
			{
				for (Hero* attackedHero : playerManager->playerArr.at(static_cast<us>(playerManager->getAttackedPlayer()))->playerHerosVec)
					if (attackedHero->getId() == playerManager->playerArr.at(static_cast<us>(playerManager->getAttackedPlayer()))->attackedHero)
					{

						break;
					}
				break;
			}

}

void Battlefield::changeBackground()
