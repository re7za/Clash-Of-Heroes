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

void BattleCardManager::clickHeroEachCard(sf::Vector2i& pos)
{
	// checking wether a card is clicked
	selectedCard = heros::none;
	/*for (BattleCard*& card : BattleCardArr)
	{
		// set default color
		card->setCardSelection(false);
		card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
			card->getSprOrginalColor().b, 255));

		if (card->getGlobalBounds().contains(static_cast<sf::Vector2f>(pos)))
		{
			if (!card->isCardSelected())
			{
				card->setCardSelection(true);
				selectedCard = card->getCardName();
				std::cout << card->getCardName() << std::endl;
				card->setColor(sf::Color(card->getSprOrginalColor().r + 40, card->getSprOrginalColor().g + 20,
					card->getSprOrginalColor().b + 20, 255));
			}
		}
	}*/
}

void BattleCardManager::heroExtracter(std::array<heros, 10> chosenHeroes)
{
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
	
	/*
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
	*/
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
