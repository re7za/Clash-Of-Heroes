
#include "AlphaManBattleCard.h"

AlphaManBattleCard::AlphaManBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("AlphaMan");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setFillColor(sf::Color(23, 152, 255));

	//hero health
	healthTxt.setString("hlt 13");

	//hero health
	damageTxt.setString("dmg 2");
}

void AlphaManBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (1).png");
	heroCardSpr.setTexture(heroCardTex);
}

void AlphaManBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}