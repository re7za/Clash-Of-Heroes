
#include "SniperBattleCard.h"

SniperBattleCard::SniperBattleCard()
{
	cardName = heros::sniper;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Sniper");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setFillColor(sf::Color(255, 198, 1));

	//hero health
	healthTxt.setString("hlt 9");

	//hero health
	damageTxt.setString("dmg 4");
}

void SniperBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (9).png");
	heroCardSpr.setTexture(heroCardTex);
}

void SniperBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}