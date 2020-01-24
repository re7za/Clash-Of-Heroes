#include "BattleCard.h"

BattleCard::~BattleCard() {}

void BattleCard::setDefaulProperties()
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


	// hero name
	heroNameTxt.setOrigin(sf::Vector2f(heroNameTxt.getGlobalBounds().width / 2, 0));
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 65,
		heroCardSpr.getPosition().y + 5));

	// hero health
	healthTxt.setCharacterSize(20);
	healthTxt.setFillColor(sf::Color(170, 170, 170));
	healthTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 20,
		heroCardSpr.getPosition().y + 40));

	// hero health
	damageTxt.setCharacterSize(20);
	damageTxt.setFillColor(sf::Color(170, 170, 170));
	damageTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 25,
		heroCardSpr.getPosition().y + 70));
}

void BattleCard::setColor(sf::Color color)
{
	heroCardSpr.setColor(color);

	healthTxt.setFillColor(color);
	damageTxt.setFillColor(color);

}

void BattleCard::setPosition(sf::Vector2f pos)
{
	heroCardSpr.setPosition(pos);
	setDefaulProperties();
}

sf::Color BattleCard::getSprOrginalColor()
{
	return SprOrginalColor;
}

void BattleCard::horizontalFlip()
{
	heroCardSpr.setScale(sf::Vector2f(-1.0f, 1.0f));
	heroCardSpr.setPosition(sf::Vector2f(heroCardSpr.getPosition().x +
		heroCardSpr.getGlobalBounds().width, heroCardSpr.getPosition().y));

	// another changes

	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x
		- heroCardSpr.getGlobalBounds().width * 1/4 - 12,
		heroCardSpr.getPosition().y + 10));

	healthTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x
		- heroCardSpr.getGlobalBounds().width / 2 + 20,
		heroCardSpr.getPosition().y + 40));

	damageTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x 
		- heroCardSpr.getGlobalBounds().width / 2 + 12,
		heroCardSpr.getPosition().y + 70));
	
	// it was toooooooooo fucking haaaard

}

heros BattleCard::getCardName()
{
	return cardName;
}

sf::Vector2f BattleCard::getPosition()
{
	return heroCardSpr.getPosition();
}

sf::FloatRect BattleCard::getGlobalBounds()
{
	return heroCardSpr.getGlobalBounds();
}

sf::Vector2f BattleCard::getHeroNamePos()
{
	return heroNameTxt.getPosition();
}

void BattleCard::setCardSelection(bool newBool)
{
	cardSelection = newBool;
}

bool BattleCard::isCardSelected()
{
	return cardSelection;
}
