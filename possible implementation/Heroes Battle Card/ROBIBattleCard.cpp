
#include "ROBIBattleCard.h"

ROBIBattleCard::ROBIBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("ROBI");
	heroNameTxt.setCharacterSize(24);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(34, 167, 143));

	//hero health
	healthTxt.setString("hlt 12");

	//hero health
	damageTxt.setString("dmg 2");
}

void ROBIBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (3).png");
	heroCardSpr.setTexture(heroCardTex);
}

void ROBIBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}