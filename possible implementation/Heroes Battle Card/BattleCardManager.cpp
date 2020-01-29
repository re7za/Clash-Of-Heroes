#include "BattleCardManager.h"

BattleCardManager::BattleCardManager()
{
}

void BattleCardManager::drawHerosCard(sf::RenderWindow* window)
{
	for (BattleCard*& card : leftCardArr)
		card->draw(window);

	for (BattleCard*& card : rightCardArr)
		card->draw(window);
}

void BattleCardManager::clickHeroEachCard(const sf::Vector2i& pos, PlayerEnum p, std::array<heros, 2>& AvatarMode)
{
	// checking wether a card is clicked
	selectedCard = heros::none;
	if (p == PlayerEnum::P1)
		for (BattleCard* card : leftCardArr)
		{
			// set default color
			card->setCardSelection(false);
			
			if (card->getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				if (card->isReady())
					if (!card->isCardSelected())
					{
						card->setCardSelection(true);
						selectedCard = card->getCardName();

						// kratos specialPower
						if (card->getCardName() == heros::kratos)
						{
							KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
							if (kratosCard->getTheClickSituation() == 0)		// not selected
								kratosCard->anotherClick();
							else if (kratosCard->getTheClickSituation() == 1)	// selected
								kratosCard->anotherClick();
							else if (kratosCard->getTheClickSituation() == 2)	// green
								kratosCard->resetTheClickSituation();
						}
						else
							for (BattleCard* card2 : leftCardArr)
								if (card2->getCardName() == heros::kratos)
								{
									KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card2);
									if (kratosCard->getTheClickSituation() == 2)		// avatar mode is active
									{
										AvatarMode.at(0) = heros::kratos;
										AvatarMode.at(1) = card->getCardName();
										kratosCard->usingKey();
										return;
									}

									kratosCard->resetTheClickSituation();
									break;
								}
						// giant specialPower
						if (card->getCardName() == heros::giant)
						{
							GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
							if (giantCard->getTheClickSituation() == 0)
								giantCard->anotherClick();
							else if (giantCard->getTheClickSituation() == 1)
								giantCard->anotherClick();
							else if (giantCard->getTheClickSituation() == 2)
								giantCard->resetTheClickSituation();
						}
						else
							for (BattleCard* card2 : leftCardArr)
								if (card2->getCardName() == heros::giant)
								{
									GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card2);
									if (giantCard->getTheClickSituation() == 2)		// avatar mode is active
									{
										AvatarMode.at(0) = heros::giant;
										AvatarMode.at(1) = card->getCardName();
										giantCard->usingKey();
										return;
									}

									giantCard->resetTheClickSituation();
									break;
								}
					}
		}
	else if (p == PlayerEnum::P2)
		for(BattleCard * card : rightCardArr)
		{
			// set default color
			card->setCardSelection(false);

			if (card->getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
				if (card->isReady())
					if (!card->isCardSelected())
					{
						card->setCardSelection(true);
						selectedCard = card->getCardName();

						// kratos specialPower
						if (card->getCardName() == heros::kratos)
						{
							KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
							if (kratosCard->getTheClickSituation() == 0)		// not selected
								kratosCard->anotherClick();
							else if (kratosCard->getTheClickSituation() == 1)	// selected
								kratosCard->anotherClick();
							else if (kratosCard->getTheClickSituation() == 2)	// green
								kratosCard->resetTheClickSituation();
						}
						else
							for (BattleCard* card2 : rightCardArr)
								if (card2->getCardName() == heros::kratos)
								{
									KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card2);

									if (kratosCard->getTheClickSituation() == 2)		// avatar mode is active
									{
										AvatarMode.at(0) = heros::kratos;
										AvatarMode.at(1) = card->getCardName();
										kratosCard->usingKey();
										return;
									}

									kratosCard->resetTheClickSituation();
									break;
								}
						// giant specialPower
						if (card->getCardName() == heros::giant)
						{
							GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
							if (giantCard->getTheClickSituation() == 0)		// not selected
								giantCard->anotherClick();
							else if (giantCard->getTheClickSituation() == 1)	// selected
								giantCard->anotherClick();
							else if (giantCard->getTheClickSituation() == 2)	// red
								giantCard->resetTheClickSituation();
						}
						else
							for (BattleCard* card2 : rightCardArr)
								if (card2->getCardName() == heros::giant)
								{
									GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card2);

									if (giantCard->getTheClickSituation() == 2)		// avatar mode is active
									{
										AvatarMode.at(0) = heros::giant;
										AvatarMode.at(1) = card->getCardName();
										giantCard->usingKey();
										return;
									}

									giantCard->resetTheClickSituation();
									break;
								}
					}
		}
}
void BattleCardManager::hoverHeroEachCard(PlayerEnum p)
{
	if (p == PlayerEnum::P1)
	{
		for (BattleCard* card : leftCardArr)
			if (card->isReady())
			{
				if (card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
				{				
					card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
						card->getSprOrginalColor().b, 255));

					// special power
					if (card->getCardName() == heros::kratos)
					{
						KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
						if (kratosCard->getTheClickSituation() == 2)
							kratosCard->setColor(sf::Color(100, 255, 100, 255));
					}
					if (card->getCardName() == heros::giant)
					{
						GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
						if (giantCard->getTheClickSituation() == 2)
							giantCard->setColor(sf::Color(255, 100, 100, 255));
					}
				}
				else
				{
					if (card->getCardName() != selectedCard)
						card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
							card->getSprOrginalColor().b - 60, 255));
				}
			}
	}
	else if (p == PlayerEnum::P2)
	{
		for (BattleCard* card : rightCardArr)
			if (card->isReady())
			{
				if (card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
				{
					card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
						card->getSprOrginalColor().b, 255));

					// special power =_(
					if (card->getCardName() == heros::kratos)
					{
						KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
						if (kratosCard->getTheClickSituation() == 2)
							kratosCard->setColor(sf::Color(100, 255, 100, 255));
					}
					if (card->getCardName() == heros::giant)
					{
						GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
						if (giantCard->getTheClickSituation() == 2)
							giantCard->setColor(sf::Color(255, 100, 100, 255));
					}
				}
				else
				{
					if (card->getCardName() != selectedCard)
						card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
							card->getSprOrginalColor().b - 60, 255));
				}
			}
	}
}
void BattleCardManager::turnWasChanged(PlayerEnum p)
{
	selectedCard = heros::none;

	if (p == PlayerEnum::P1)
	{
		// turn off the right cards
		for (BattleCard* card : rightCardArr)
			if (card->isAlive())
				card->setColor(sf::Color(card->getSprOrginalColor().r - 100, card->getSprOrginalColor().g - 100,
					card->getSprOrginalColor().b - 100, 220));

		// turn on the left cards
		for (BattleCard* card : leftCardArr)
		{
			if (card->isAlive())
				card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
					card->getSprOrginalColor().b - 60, 255));

			// special power
			if (card->getCardName() == heros::kratos)
			{
				KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
				kratosCard->resetTheClickSituation();
			}
			if (card->getCardName() == heros::giant)
			{
				GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
				giantCard->resetTheClickSituation();
			}
		}

	}
	else if (p == PlayerEnum::P2)
	{
		// turn off the left cards
		for (BattleCard* card : leftCardArr)
			if (card->isAlive())
				card->setColor(sf::Color(card->getSprOrginalColor().r - 100, card->getSprOrginalColor().g - 100,
					card->getSprOrginalColor().b - 100, 220));

		// turn on the right cards
		for (BattleCard* card : rightCardArr)
		{
			if (card->isAlive())
				card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
					card->getSprOrginalColor().b - 60, 255));

			// special power
			if (card->getCardName() == heros::kratos)
			{
				KratosBattleCard* kratosCard = dynamic_cast<KratosBattleCard*> (card);
				kratosCard->resetTheClickSituation();
			}
			if (card->getCardName() == heros::giant)
			{
				GiantBattleCard* giantCard = dynamic_cast<GiantBattleCard*> (card);
				giantCard->resetTheClickSituation();
			}
		}
	}
}

void BattleCardManager::heroExtracter(std::array<heros, 10> chosenHeroes)
{
	///////////////// test
	chosenHeroes.at(0) = heros::alphaMan;
	chosenHeroes.at(1) = heros::rickKhonsari;
	chosenHeroes.at(2) = heros::giant;
	chosenHeroes.at(3) = heros::mrsGhost;
	chosenHeroes.at(4) = heros::commander;
	chosenHeroes.at(5) = heros::kratos;
	chosenHeroes.at(6) = heros::sniper;
	chosenHeroes.at(7) = heros::robi;
	chosenHeroes.at(8) = heros::leon;
	chosenHeroes.at(9) = heros::professor;

	// fill the leftCardArr
	for (us i = 0; i < 5; i++)
		switch (chosenHeroes.at(i))
		{
		case heros::alphaMan:
			leftCardArr.at(i) = new AlphaManBattleCard();
			break;
		case heros::commander:
			leftCardArr.at(i) = new CommanderBattleCard();
			break;
		case heros::drMarry:
			leftCardArr.at(i) = new DrMarryBattleCard();
			break;
		case heros::giant:
			leftCardArr.at(i) = new GiantBattleCard();
			break;
		case heros::kratos:
			leftCardArr.at(i) = new KratosBattleCard();
			break;
		case heros::leon:
			leftCardArr.at(i) = new LeonBattleCard();
			break;
		case heros::mrsGhost:
			leftCardArr.at(i) = new MrsGhostBattleCard();
			break;
		case heros::professor:
			leftCardArr.at(i) = new ProfessorBattleCard();
			break;
		case heros::rickKhonsari:
			leftCardArr.at(i) = new RickKhonsariBattleCard();
			break;
		case heros::robi:
			leftCardArr.at(i) = new ROBIBattleCard();
			break;
		case heros::sniper:
			leftCardArr.at(i) = new SniperBattleCard();
			break;
		case heros::sybil:
			leftCardArr.at(i) = new SybilBattleCard();
			break;
		}

	// fill the rightCardArr
	for (us i = 0; i < 5; i++)
		switch (chosenHeroes.at(i + 5))
		{
		case heros::alphaMan:
			rightCardArr.at(i) = new AlphaManBattleCard();
			break;
		case heros::commander:
			rightCardArr.at(i) = new CommanderBattleCard();
			break;
		case heros::drMarry:
			rightCardArr.at(i) = new DrMarryBattleCard();
			break;
		case heros::giant:
			rightCardArr.at(i) = new GiantBattleCard();
			break;
		case heros::kratos:
			rightCardArr.at(i) = new KratosBattleCard();
			break;
		case heros::leon:
			rightCardArr.at(i) = new LeonBattleCard();
			break;
		case heros::mrsGhost:
			rightCardArr.at(i) = new MrsGhostBattleCard();
			break;
		case heros::professor:
			rightCardArr.at(i) = new ProfessorBattleCard();
			break;
		case heros::rickKhonsari:
			rightCardArr.at(i) = new RickKhonsariBattleCard();
			break;
		case heros::robi:
			rightCardArr.at(i) = new ROBIBattleCard();
			break;
		case heros::sniper:
			rightCardArr.at(i) = new SniperBattleCard();
			break;
		case heros::sybil:
			rightCardArr.at(i) = new SybilBattleCard();
			break;
		}
	
}

void BattleCardManager::setGridsCardsPos(sf::Vector2f gridPos, sf::FloatRect gridBounds)
{
	
	for (us i = 0; i < leftCardArr.size(); i++)
	{
		leftCardArr.at(i)->setPosition(sf::Vector2f(
			gridPos.x - leftCardArr.at(i)->getGlobalBounds().width - 5,
			gridPos.y + i * (leftCardArr.at(i)->getGlobalBounds().height + 4) + 20));
	}

	for (us i = 0; i < rightCardArr.size(); i++)
	{
		// set its position
		rightCardArr.at(i)->setPosition(sf::Vector2f(
			gridPos.x + gridBounds.width + 5,
			gridPos.y + i * (rightCardArr.at(i)->getGlobalBounds().height + 4) + 20));

		// flip the card
		rightCardArr.at(i)->horizontalFlip();
		
	}
}

void BattleCardManager::setSelectedCard(heros cardName)
{
	selectedCard = cardName;
}

heros BattleCardManager::getSelectedCard()
{
	return selectedCard;
}

heros& BattleCardManager::getSelectedCardByRefrence()
{
	return selectedCard;
}

void BattleCardManager::updateInfo(const std::vector<Hero*>& leftHeroesVec, const std::vector<Hero*>& rightHeroesVec)
{
	for (BattleCard* card : leftCardArr)
		for (Hero* hero : leftHeroesVec)
			if (hero->getId() == card->getCardName())
			{
				if (card->getCardName() != heros::mrsGhost)		// exception : Mrs.Ghost
					card->setHealthTxt("hlt " + std::to_string(hero->getHealth()));
				else
				{
					if (hero->isHidden())
						card->setHealthTxt("hlt  X");
					else		// she's hide
						card->setHealthTxt("hlt " + std::to_string(hero->getHealth()));
				}


				if (!hero->isAlive())
				{
					card->setAliveness(false);
					card->setColor(sf::Color(card->getSprOrginalColor().r - 180, card->getSprOrginalColor().g - 180,
						card->getSprOrginalColor().b - 180, 220));
				}

				break;
			}

	for (BattleCard* card : rightCardArr)
		for (Hero* hero : rightHeroesVec)
			if (hero->getId() == card->getCardName())
			{
				if (card->getCardName() != heros::mrsGhost)		// exception : Mrs.Ghost
					card->setHealthTxt("hlt " + std::to_string(hero->getHealth()));
				else
				{
					if (hero->isHidden())
						card->setHealthTxt("hlt  X");
					else		// she's hide
						card->setHealthTxt("hlt " + std::to_string(hero->getHealth()));
				}


				if (!hero->isAlive())
				{
					card->setAliveness(false);
					card->setColor(sf::Color(card->getSprOrginalColor().r - 150, card->getSprOrginalColor().g - 150,
						card->getSprOrginalColor().b - 150, 180));
				}

				break;
			}

}

