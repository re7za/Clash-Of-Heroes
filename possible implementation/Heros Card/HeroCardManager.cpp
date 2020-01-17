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
	// checking wether a card is clicked
	selectedCard = heros::none;
	for (HerosCard* & card : heroCardVec)
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

	/*// checking another NULL area :)
	us cardCounter = 0;
	for (HerosCard*& card : heroCardVec)
		if (pos.x >= card->getGlobalBound().left && pos.x <= card->getPosition().x + 150
			&& pos.y >= card->getGlobalBound().top && pos.y <= card->getPosition().y + 230
			&& pos.x >= tiles.at(i).at(j)->getPosition().x
			&& pos.x < tiles.at(i).at(j)->getPosition().x + tiles.at(i).at(j)->getGlobalBound().width
			&& pos.y >= tiles.at(i).at(j)->getPosition().y
			&& pos.y < tiles.at(i).at(j)->getPosition().y + tiles.at(i).at(j)->getGlobalBound().height)
			// خب یکاری کن ک فقط روی گرید نباشه سلکت نان بشه2
			// میخوایم چک کنیم کع اگه پوزیشن کلیک شده چیزی جز کارت ها و گریده سلکت کارت مساوی نان بشه1
	*/

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
