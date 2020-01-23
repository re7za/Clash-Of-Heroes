
#include "CommanderBattleCard.h"

CommanderBattleCard::CommanderBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Commander");
	heroNameTxt.setCharacterSize(16);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 25,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(174, 32, 49));

	//hero health
	healthTxt.setString("hlt 7");

	//hero health
	damageTxt.setString("dmg 3");
}

void CommanderBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (2).png");
	heroCardSpr.setTexture(heroCardTex);
}

void CommanderBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}