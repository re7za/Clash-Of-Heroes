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

void BattleCardManager::clickHeroEachCard(const sf::Vector2i& pos, PlayerEnum p)
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
					}
		}
	else
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
				}
				else
				{
					if (card->getCardName() != selectedCard)
						card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
							card->getSprOrginalColor().b - 60, 255));
				}
			}
	}
	else
	{
		for (BattleCard* card : rightCardArr)
			if (card->isReady())
			{
				if (card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
					card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
						card->getSprOrginalColor().b, 255));
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
			card->setColor(sf::Color(card->getSprOrginalColor().r - 100, card->getSprOrginalColor().g - 100,
				card->getSprOrginalColor().b - 100, 220));

		// turn on the left cards
		for (BattleCard* card : leftCardArr)
			card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
				card->getSprOrginalColor().b - 60, 255));
	}
	else
	{
		// turn off the left cards
		for (BattleCard* card : leftCardArr)
			card->setColor(sf::Color(card->getSprOrginalColor().r - 100, card->getSprOrginalColor().g - 100,
				card->getSprOrginalColor().b - 100, 220));

		// turn on the right cards
		for (BattleCard* card : rightCardArr)
			card->setColor(sf::Color(card->getSprOrginalColor().r - 60, card->getSprOrginalColor().g - 60,
				card->getSprOrginalColor().b - 60, 255));
	}
}


void BattleCardManager::heroExtracter(std::array<heros, 10> chosenHeroes)
{
	/*
	leftCardArr.at(0) = new AlphaManBattleCard();
	leftCardArr.at(1) = new KratosBattleCard();
	leftCardArr.at(2) = new DrMarryBattleCard();
	leftCardArr.at(3) = new CommanderBattleCard();
	leftCardArr.at(4) = new LeonBattleCard();
	rightCardArr.at(0) = new MrsGhostBattleCard();
	rightCardArr.at(1) = new ProfessorBattleCard();
	rightCardArr.at(2) = new RickKhonsariBattleCard();
	rightCardArr.at(3) = new SniperBattleCard();
	rightCardArr.at(4) = new SybilBattleCard();
	*/
	

	///////////////// test
	chosenHeroes.at(0) = heros::alphaMan;
	chosenHeroes.at(1) = heros::rickKhonsari;
	chosenHeroes.at(2) = heros::giant;
	chosenHeroes.at(3) = heros::mrsGhost;
	chosenHeroes.at(4) = heros::professor;
	chosenHeroes.at(5) = heros::sybil;
	chosenHeroes.at(6) = heros::sniper;
	chosenHeroes.at(7) = heros::robi;
	chosenHeroes.at(8) = heros::leon;
	chosenHeroes.at(9) = heros::drMarry;

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
