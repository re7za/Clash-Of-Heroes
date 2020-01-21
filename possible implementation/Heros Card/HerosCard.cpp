
#include "HerosCard.h"

void HerosCard::setDefaulProperties()
{
	// hero SprColor
	heroCardSpr.setColor(sf::Color(heroCardSpr.getColor().r - 40, heroCardSpr.getColor().g - 40,
		heroCardSpr.getColor().b - 40, 255));

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

HerosCard::~HerosCard()
{
}

void HerosCard::setColor(sf::Color color)
{
	heroCardSpr.setColor(color);
}
sf::Color HerosCard::getSprOrginalColor()
{
	return SprOrginalColor;
}

heros HerosCard::getCardName()
{
	return cardName;
}

sf::Vector2f HerosCard::getPosition()
{
	return heroCardSpr.getPosition();
}

sf::FloatRect HerosCard::getGlobalBound()
{
	return heroCardSpr.getGlobalBounds();
}

// card selection
void HerosCard::setCardSelection(bool newBool)
{
	cardSelection = newBool;
}
bool HerosCard::isCardSelected()
{
	return cardSelection;
}