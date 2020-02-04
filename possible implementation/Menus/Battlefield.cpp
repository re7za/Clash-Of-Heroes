#include "Battlefield.h"
#include <iostream>

Battlefield::Battlefield()
	:pauseWidget (new Widget("Main Menu", "New Game", "Restart")),
	endingWidget (new Widget("Main Menu", "New Game", "Restart"))
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

	// pause button
	pauseBtn.setString("pause");
	pauseBtn.setCharacterSize(60);
	pauseBtn.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width - 200, 10));
	// its widget
	pauseWidget->setMessageString("what do you want to do?");

	// panel
	// panelP1
	panelP1.setString("Hero I");
	panelP1.setCharacterSize(60);
	panelP1.setOutlineThinkness(20);
	panelP1.setOutlineColor(sf::Color(0, 0, 0, 200));
	panelP1.setFillColor(sf::Color(255, 0, 0, 200));
	panelP1.setOrginalFillColor(panelP1.getFillColor());
	panelP1.setPosition(sf::Vector2f(grid.getPosition().x + 50, 25));
	// panelP2
	panelP2.setString("Hero II");
	panelP2.setCharacterSize(60);
	panelP2.setOutlineThinkness(20);
	panelP2.setOutlineColor(sf::Color(0, 0, 0, 200));
	panelP2.setFillColor(sf::Color(255, 0, 0, 200));
	panelP2.setOrginalFillColor(panelP2.getFillColor());
	panelP2.setPosition(sf::Vector2f(grid.getPosition().x + grid.getGlobalBound().width
		- panelP2.getGlobalBounds().width, 25));
	// timer
	timer.setFillColor(sf::Color(230, 230, 230, 255));
	timer.setOutlineThinkness(8);
	timer.setOutlineColor(sf::Color(20, 20, 20, 255));
	timer.setPosition(sf::Vector2f(grid.getPosition().x + grid.getGlobalBound().width / 2
		- timer.getGlobalBounds().width / 2 + 8, 10));

	
	/*/////////////// test
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Sybil(sf::Vector2i(0, 0)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new RickKhonsari(sf::Vector2i(0, 1)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Giant(sf::Vector2i(0, 2)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new MrsGhost(sf::Vector2i(0, 3)));
	playerManager->playerArr.at(0)->playerHerosVec.push_back(new Kratos(sf::Vector2i(0, 4)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Kratos(sf::Vector2i(1, 0)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Sniper(sf::Vector2i(1, 1)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Giant(sf::Vector2i(1, 2)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Leon(sf::Vector2i(1, 3)));
	playerManager->playerArr.at(1)->playerHerosVec.push_back(new Professor(sf::Vector2i(1, 4)));
	*//////////////////////
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

	// panel
	panelP1.draw(window);
	panelP2.draw(window);
	timer.draw(window);

	// battle cards
	battleCardManager.drawHerosCard(window);

	// widgets
	if (pauseWidget->activation == true)
		pauseWidget->draw(window);

	if (endingWidget->activation == true)
		endingWidget->draw(window);
}

/////// mouse events and positions
void Battlefield::click(sf::Vector2i& pos, menuType& currentMenu)
{
	if (pauseWidget->activation == false
		&& endingWidget->activation == false)
	{
		// grid and check for turn changing =)))))))))))
		bool isTurnChange = false;
		if (grid.getGlobalBound().contains(sf::Vector2f(pos)) && battleCardManager.getSelectedCard() != heros::none)
			grid.battlefieldClicked(pos, playerManager, isTurnChange);

		if (isTurnChange)
		{
			timer.Start();

			// attack process by player.attackedPlayer and battleCard.selectedCard =))
			attackProcess();

			// update card's info
			battleCardManager.updateInfo(playerManager->playerArr.at(static_cast<us> (Players::P1))->playerHerosVec,
				playerManager->playerArr.at(static_cast<us> (Players::P2))->playerHerosVec);

			// changing the turn.. it must be after attack process
			playerManager->changeTheTurn();
			turnWasChanged(playerManager->getTheTurn());
			return;
		}
	
		//////////////////////////////// cards
		std::array<heros, 2> AvatarModeSides = {heros::none, heros::none};	// (avatar, his teammate)
		battleCardManager.clickHeroEachCard(pos, static_cast<PlayerEnum>(playerManager->getTheTurn()), AvatarModeSides);

		if (AvatarModeSides.at(1) != heros::none)
		{
			// specialPower process
			helpingTeammates(AvatarModeSides);

			// update card's info
			battleCardManager.updateInfo(playerManager->playerArr.at(static_cast<us> (Players::P1))->playerHerosVec,
				playerManager->playerArr.at(static_cast<us> (Players::P2))->playerHerosVec);

			// changing the turn.. it must be after attack process
			playerManager->changeTheTurn();
			turnWasChanged(playerManager->getTheTurn());
			return;
		}

		//////////// pause btn
		if (pauseBtn.getGlobalBound().contains(sf::Vector2f(pos)))
			pauseWidget->activation = true;
	}
	else if (pauseWidget->activation == true)
	{
		// click pos is out of widget pos or not
		if (!(pauseWidget->isClicked(sf::Vector2f(pos))))
			pauseWidget->activation = false;
		else
		{
			bool isRestartBtnClicked = false;
			pauseWidget->clicked(sf::Vector2f(pos), currentMenu, menuType::mainMenu, menuType::heroSelection, isRestartBtnClicked);

			// if the third btn clicked
			if (isRestartBtnClicked == true)
				restartTheGame();

			// restart the timer
			if (currentMenu != menuType::battlefield)
			{
				timer.restart();
				timer.Stop();
			}
		}	
	}
	else if (endingWidget->activation == true)
	{
		if (endingWidget->isClicked(sf::Vector2f(pos)))
		{
			bool isRestartBtnClicked = false;
			endingWidget->clicked(sf::Vector2f(pos), currentMenu, menuType::mainMenu, menuType::heroSelection, isRestartBtnClicked);

			// if the third btn clicked
			if (isRestartBtnClicked == true)
				restartTheGame();

			// restart the timer
			if (currentMenu != menuType::battlefield)
			{
				timer.restart();
				timer.Stop();
			}
		}
	}
}

void Battlefield::mouseHover(sf::RenderWindow*)
{	
	if (pauseWidget->activation == false
		&& endingWidget->activation == false)
	{
		pauseBtn.onMouseOver();
		// cards
		battleCardManager.hoverHeroEachCard(static_cast<PlayerEnum>(playerManager->getTheTurn()));
	}
	else if (pauseWidget->activation == true)
	{
		pauseWidget->onMouseHover();
	}
	else if (endingWidget->activation == true)
	{
		endingWidget->onMouseHover();
	}


}
//////////////////////////////////

// background img
void Battlefield::startTheBattlefield()
{
	// at first.. extract the chosenHeroes
	battleCardManager.heroExtracter(playerManager->getTheChosenHeroes());

	// and then set the cards position
	battleCardManager.setGridsCardsPos(grid.getPosition(), grid.getGlobalBound());

	// planting the hero in the grid
	playerManager->headsOrTails();
	turnWasChanged(playerManager->getTheTurn());
}

void Battlefield::turnWasChanged(Players playerTurn)
{
	// changing the cards
	battleCardManager.turnWasChanged(static_cast<PlayerEnum>(playerTurn));

	// attackedHero must set to none before next attack.. and "don't change the index"!
	playerManager->playerArr.at(static_cast<us>(playerManager->getTheTurn()))->attackedHero = heros::none;
	playerManager->playerArr.at(static_cast<us>(playerManager->getAttackedPlayer()))->attackedHero = heros::none;

	// panel
	if (playerTurn == Players::P1)
	{
		panelP1.setFillColor(sf::Color(panelP1.getOrginalFillColor().r, panelP1.getOrginalFillColor().g,
			panelP1.getOrginalFillColor().b, panelP1.getOrginalFillColor().a));

		panelP2.setFillColor(sf::Color(90, 0, 0, panelP2.getOrginalFillColor().a));
	}
	else
	{
		panelP1.setFillColor(sf::Color(90, 0, 0, panelP1.getOrginalFillColor().a));

		panelP2.setFillColor(sf::Color(panelP2.getOrginalFillColor().r, panelP2.getOrginalFillColor().g,
			panelP2.getOrginalFillColor().b, panelP2.getOrginalFillColor().a));
	}
	

	// planting new heroes
	if (playerTurn == Players::P1)
		grid.plantingHeroes(playerManager->playerArr.at(static_cast<us>(Players::P2))->playerHerosVec,
			playerManager->playerArr.at(static_cast<us>(playerTurn))->attackPosStatucVec);
	else
		grid.plantingHeroes(playerManager->playerArr.at(static_cast<us>(Players::P1))->playerHerosVec,
			playerManager->playerArr.at(static_cast<us>(playerTurn))->attackPosStatucVec);

	// end checking
	// player1 checker
	us player1deads = 0;
	for (Hero* hero : playerManager->playerArr.at(0)->playerHerosVec)
		if (!hero->isAlive())
			player1deads++;
	if (player1deads == 5)
	{
		endingWidget->setMessageString("Hero II wins!!");
		endingWidget->activation = true;
		
	}
	// player2 checker
	us player2deads = 0;
	for (Hero* hero : playerManager->playerArr.at(1)->playerHerosVec)
		if (!hero->isAlive())
			player2deads++;
	if (player2deads == 5)
	{
		endingWidget->setMessageString("Hero I wins!!");
		endingWidget->activation = true;
	}


}

void Battlefield::attackProcess()
{
	/////////////Prevent multiple calling functions
	// attacked player properties..
	Players attackedPlayer = playerManager->getAttackedPlayer();
	heros attackedHeroName = playerManager->playerArr.at(static_cast<us>(attackedPlayer))->attackedHero;
	std::vector<Hero*>& attackedHeroesVec = playerManager->playerArr.at(static_cast<us>(attackedPlayer))->playerHerosVec;

	// attacker player properties...
	Players attackerPlayer = playerManager->getTheTurn();
	heros attackerHeroName = battleCardManager.getSelectedCard();
	std::vector<Hero*>& attackerHeroesVec = playerManager->playerArr.at(static_cast<us>(attackerPlayer))->playerHerosVec;
	sf::Vector2i attackPos = playerManager->playerArr.at(static_cast<us> (attackerPlayer))->getAttackPos();
	/////////////////////////////////////////////*/

	// start the war
	//////////////////// basic attack
	if (attackedHeroName != heros::none)
		for (Hero* attackerHero : attackerHeroesVec)
			if (attackerHero->getId() == attackerHeroName)
			{
				for (Hero* attackedHero : attackedHeroesVec)
					if (attackedHero->getId() == attackedHeroName)
					{
						attackerHero->attack(attackedHero, attackedHeroesVec);

						// در ادامه اینجا احتمالا باید تغییرات اعمالی روی هیرو تحت اتک.. روی کارتش هم اعمال بشه پراببلی.. شایدم اینجا نه
						break;
					}

				break;
			}

	////////////////// special powers
	// robi
	if (attackerHeroName == heros::robi)
		for (Hero* attackerHero : attackerHeroesVec)
			if (attackerHero->getId() == attackerHeroName)
			{
				ROBI* robi = dynamic_cast<ROBI*>(attackerHero);
				robi->specialPower(attackedHeroesVec, attackPos);
				break;
			}

	// alpha man
	if (attackerHeroName == heros::alphaMan)
		for (Hero* attackerHero : attackerHeroesVec)
			if (attackerHero->getId() == attackerHeroName)
			{
				AlphaMan* alphaMan = dynamic_cast<AlphaMan*>(attackerHero);
				alphaMan->specialPower(attackedHeroesVec, attackPos);
				break;
			}

	// ramin
	if (attackerHeroName == heros::rickKhonsari)
		for (Hero* attackerHero : attackerHeroesVec)
			if (attackerHero->getId() == attackerHeroName)
			{
				RickKhonsari* ramin = dynamic_cast<RickKhonsari*>(attackerHero);
					for (Hero* attacked : attackedHeroesVec)
						if (attacked->getId() == attackedHeroName)	// checks whether the attacking is successful or not
						{
							if (attacked->getHeroPosition() == attackPos)
							{
								// special power starts here =|
								sf::Vector2i tile;
								std::vector<sf::Vector2i> _tiles;
								for (us i = 0; i < ramin->getSpecialTimes(); i++)
								{
									tile = sf::Vector2i(rand() % 9, rand() % 9);
									bool repetitive = false;
									for (sf::Vector2i& _tile : _tiles)
										if (tile == _tile)
										{
											repetitive = true;
											break;
										}

									if (repetitive == false)
									{
										_tiles.push_back(tile);

										for (Hero* attackeddd : attackedHeroesVec)
											if (attackeddd->getHeroPosition() == tile)
											{
												attackeddd->setHideness(false);
												// جلوه های گرافیکی هم میخواد
											}
									}
									else
									{
										i--;
										continue;
									}
								}
							}

							break;
						}
					

				break;
			}
				
	// sybil
	if (attackerHeroName == heros::sybil)
		for (Hero* attackerHero : attackerHeroesVec)
			if (attackerHero->getId() == attackerHeroName)
			{
				Sybil* sybil = dynamic_cast<Sybil*>(attackerHero);
				for (Hero* attacked : attackedHeroesVec)
					if (attacked->getId() == attackedHeroName)	// checks whether the attacking is successful or not
					{
						bool key = true;
						while (key)
						{
							us deads = 0;
							for (Hero* deadHeroes : attackedHeroesVec)
								if (deadHeroes->getId() != attackedHeroName)
									if (!deadHeroes->isAlive())
										deads++;
							if (deads == 4)
								key = false;

							//
							us r = rand() % 5;
							if (attackedHeroesVec.at(r)->isAlive())
								if (attackedHeroesVec.at(r)->getId() != attackedHeroName)
									if (rand() % 2 == 1)			// half chance
									{
										// with about half power
										attackedHeroesVec.at(r)->decreaseHealth(static_cast<us>(attacked->getDamage() / 2) + 1);
										key = false;
									}
						}

						break;
					}
				break;
			}

	
	/*///////////////////////////// Log
		//don't delete this comment
	std::cout << "get the turn              : " << static_cast <int> (playerManager->getTheTurn()) << std::endl;
	std::cout << "get attacked player       : " << static_cast <int> (playerManager->getAttackedPlayer()) << std::endl;
	std::cout << "selected card (attacher)  : " << static_cast <int> (battleCardManager.getSelectedCard()) << std::endl;
	std::cout << "attacked Hero             : " << static_cast <int> (playerManager->playerArr
		.at(static_cast <int> (playerManager->getAttackedPlayer()))->attackedHero) << std::endl;

	std::cout << "//////attacked player :" << std::endl;
	for (Hero* attacked : attackedHeroesVec)
		std::cout << "Id : " << attacked->getId() << "   hlt : " << attacked->getHealth() << "   dmg : " << attacked->getDamage()
		<< "   isHidden : " << attacked->isHidden() << "   isAlive : " << attacked->isAlive() << std::endl;

	std::cout << "//////attacker player :" << std::endl;
	for (Hero* attacker : attackerHeroesVec)
		std::cout << "Id : " << attacker->getId() << "   hlt : " << attacker->getHealth() << "   dmg : " << attacker->getDamage()
		<< "   isHidden : " << attacker->isHidden() << "   isAlive : " << attacker->isAlive() << std::endl;

	std::cout << "//////////////////////////////////" << std::endl;
	/////////////////////////////////////*/

}

void Battlefield::helpingTeammates(std::array<heros, 2>& AvatarModeSides)
{

	/////////////Prevent multiple calling functions
	// attacker player properties...
	std::vector<Hero*>& attackerHeroesVec = playerManager->playerArr.at(static_cast<us>(playerManager->getTheTurn()))->playerHerosVec;

	heros& AvatarName = AvatarModeSides.at(0);
	heros& teammateName = AvatarModeSides.at(1);
	///////////////////////////////////////////////

	// 
	switch (AvatarName)
	{
	case heros::kratos:
	{
		for (Hero* hero : attackerHeroesVec)
			if (hero->getId() == heros::kratos)
			{
				Kratos* kratos = dynamic_cast<Kratos*> (hero);
				for (Hero* teammateHero : attackerHeroesVec)
					if (teammateHero->getId() == teammateName)
					{
						us i, j;
						sf::Vector2i newPos;
						us antiHang = 100;
						while (true)	// generating a random empty position
						{
							antiHang--;
							us i = rand() % 9;
							us j = rand() % 9;
							newPos = sf::Vector2i(i, j);

							bool repetitive = false;
							bool redZone = false;
							for (Hero* ourHero : attackerHeroesVec)
								if (ourHero->getHeroPosition() == newPos)
								{
									repetitive = true;
									break;
								}

							for (const attacekPosStatus& tileStatus : playerManager->playerArr
								.at(static_cast<us> (playerManager->getAttackedPlayer()))->attackPosStatucVec)
							{
								if (newPos == tileStatus.pos)
									if (tileStatus.status == tileType::L3)
									{
										redZone = true;
										break;
									}
							
							}

							// بعدا جعبه هارم باید ب این لیست اضافه کنی

							if (repetitive == false && redZone == false)
								break;

							// preventing infinitive loop
							if (antiHang == 0)
								break;
						}
						
						kratos->AvatarMode(teammateHero, newPos);
						break;
					}

				break;
			}

		break;
	}

	case heros::giant:
	{
		for (Hero* hero : attackerHeroesVec)
			if (hero->getId() == heros::giant)
			{
				Giant* giant = dynamic_cast<Giant*> (hero);
				for (Hero* teammateHero : attackerHeroesVec)
					if (teammateHero->getId() == teammateName)
					{
						giant->HellBoyMode(teammateHero);

						break;
					}

				break;
			}

		break;
	}
	}
}

void Battlefield::changeBackground()
{
	switch (rand() % 8)
	{
	case 0:
		backgroundTex.loadFromFile("Menus/background/game1.png");
		grid.setFillColor(sf::Color(100, 50, 0, 255));
		break;
	case 1:
		backgroundTex.loadFromFile("Menus/background/game2.png");
		grid.setFillColor(sf::Color(100, 100, 150, 255));
		break;
	case 2:
		backgroundTex.loadFromFile("Menus/background/game1.png");
		grid.setFillColor(sf::Color(100, 50, 0, 255));
		break;
	case 3:
		backgroundTex.loadFromFile("Menus/background/game4.png");
		grid.setFillColor(sf::Color(70, 80, 65, 255));
		break;
	case 4:
		backgroundTex.loadFromFile("Menus/background/game5.png");
		grid.setFillColor(sf::Color(70, 50, 50, 255));
		break;
	case 5:
		backgroundTex.loadFromFile("Menus/background/game5.png");
		grid.setFillColor(sf::Color(70, 50, 50, 255));
		break;
	case 6:
		backgroundTex.loadFromFile("Menus/background/game6.jpg");
		grid.setFillColor(sf::Color(80, 0, 20, 255));
		break;
	case 7:
		backgroundTex.loadFromFile("Menus/background/game6.jpg");
		grid.setFillColor(sf::Color(80, 0, 20, 255));
		break;
	}

	menuSpr.setTexture(backgroundTex);
}

void Battlefield::restartTheGame()
{
	///////////////////////// restart the grid
	grid.clearAllTiles();

	///////////////////////// restart the heroes
	// at first make a backup from hero's positions
	std::vector<sf::Vector2i> herosPos;
	for (Player* player : playerManager->playerArr)
		for (Hero* hero : player->playerHerosVec)
			herosPos.push_back(hero->getHeroPosition());

	// and then clear the hero's vec
	playerManager->clearPlayerMemory();

	// now ..make new hereos
	for (us p = 0; p < playerManager->playerArr.size(); p++)
		for (us j = 0; j < playerManager->getTheChosenHeroes().size() / 2; j++)
		{
			switch (playerManager->getTheChosenHeroes().at(j + p * (playerManager->getTheChosenHeroes().size() / 2)))
			{
			case heros::mrsGhost:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new MrsGhost(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::robi:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new ROBI(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::leon:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Leon(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::drMarry:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new DrMarry(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::sniper:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Sniper(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::kratos:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Kratos(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::giant:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Giant(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::alphaMan:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new AlphaMan(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::professor:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Professor(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::commander:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Commander(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::rickKhonsari:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new RickKhonsari(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			case heros::sybil:
			{
				playerManager->playerArr.at(p)->playerHerosVec.push_back(new Sybil(herosPos.at(j + p * (playerManager->getTheChosenHeroes().size() / 2))));
				break;
			}
			}
		}
			
	////////////////////////// restart the battle cards
	battleCardManager.clearAllCards();
	startTheBattlefield();

	playerManager->headsOrTails();
	turnWasChanged(playerManager->getTheTurn());
	
	////////////////////////// restart the timer
	timer.restart();
	timer.Stop();
}
