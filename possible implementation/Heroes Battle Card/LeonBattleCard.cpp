
#include "LeonBattleCard.h"

LeonBattleCard::LeonBattleCard()
{
	cardName = heros::leon;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Leon");
	heroNameTxt.setCharacterSize(24);
	heroNameTxt.setFillColor(sf::Color(245, 96, 48));

	//hero health
	healthTxt.setString("hlt 10");

	//hero health
	damageTxt.setString("dmg 3");
}

void LeonBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (10).png");
	heroCardSpr.setTexture(heroCardTex);
}

void LeonBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}