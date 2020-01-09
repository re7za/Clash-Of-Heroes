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
	for (HerosCard* card : heroCardVec)
		card->draw(window);

}

void HeroCardManager::rightClickHeroEachCard(sf::Vector2i& pos)
{
	static int a = 0;
	for (HerosCard* card : heroCardVec)
	{
		// set default color
		card->setCardSelection(false);
		card->setColor(sf::Color(card->getSprOrginalColor().r, card->getSprOrginalColor().g,
			card->getSprOrginalColor().b, 255));

		if (pos.x >= card->getGlobalBound().left && pos.x <= card->getPosition().x + 150
			&& pos.y >= card->getGlobalBound().top && pos.y <= card->getPosition().y + 230)
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
