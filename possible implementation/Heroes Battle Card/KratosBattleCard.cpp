
#include "KratosBattleCard.h"

KratosBattleCard::KratosBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Kratos");
	heroNameTxt.setCharacterSize(22);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(31, 170, 34));

	//hero health
	healthTxt.setString("hlt 15");

	//hero health
	damageTxt.setString("dmg 3");
}

void KratosBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (6).png");
	heroCardSpr.setTexture(heroCardTex);
}

void KratosBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}