
#include "HerosCard.h"


void HerosCard::setDefaulProperties()
{
	// hero name
	nameFont.loadFromFile("Font/fighting spirit TBS.ttf");
	heroNameTxt.setFont(nameFont);

	// proeprties
	propertiFont.loadFromFile("Font/properties.ttf");
	healthTxt.setFont(propertiFont);
	healthTxt.setCharacterSize(12);
	damageTxt.setFont(propertiFont);
	damageTxt.setCharacterSize(12);

	//hero health
	healthTxt.setCharacterSize(14);
	healthTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 25,
		heroCardSpr.getPosition().y + 33));

	//hero health
	damageTxt.setCharacterSize(14);
	damageTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 85,
		heroCardSpr.getPosition().y + 33));
}

void HerosCard::setCardName(std::string cardName)
{
	this->cardName = cardName;
}

std::string HerosCard::getCardName()
{
	return cardName;
}
