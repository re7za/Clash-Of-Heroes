
#include "GiantBattleCard.h"

GiantBattleCard::GiantBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Giant");
	heroNameTxt.setCharacterSize(22);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(244, 55, 53));

	//hero health
	healthTxt.setString("hlt 20");

	//hero health
	damageTxt.setString("dmg 4");
}

void GiantBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (5).png");
	heroCardSpr.setTexture(heroCardTex);
}

void GiantBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}