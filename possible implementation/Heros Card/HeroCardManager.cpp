#pragma once
#include "HeroCardManager.h"

HeroCardManager::HeroCardManager()
{
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

void HeroCardManager::drawHerosCard(sf::RenderWindow* window)
{
	for (HerosCard*& card : heroCardVec)
		card->draw(window);
}

void HeroCardManager::clickHeroEachCard(sf::Vector2i& pos)
{
	// checking wether a card is clicked
	selectedCard = heros::none;
	for (HerosCard*& card : heroCardVec)
	{
		// set default color
		card->setCardSelection(false);
		card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
			card->getSprOrginalColor().b, 255));

		if (card->getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
		{
			if (!card->isCardSelected())
			{
				card->setCardSelection(true);
				selectedCard = card->getCardName();
				//std::cout << card->getCardName() << std::endl;
				card->setColor(sf::Color(card->getSprOrginalColor().r + 40, card->getSprOrginalColor().g + 20,
					card->getSprOrginalColor().b + 20, 255));
			}
		}
	}
}

void HeroCardManager::hoverHeroEachCard()
{
	for (HerosCard* card : heroCardVec)
		if (card->getGlobalBound().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			card->setColor(sf::Color::White);
		}
		else
		{
			card->setColor(card->getSprOrginalColor());
		}
}

// card selection
void HeroCardManager::setSelectedCard(heros cardName)
{
	selectedCard = cardName;
}
heros HeroCardManager::getSelectedCard()
{
	return selectedCard;
}

heros& HeroCardManager::getSelectedCardByRefrence()
{
	return selectedCard;
}
