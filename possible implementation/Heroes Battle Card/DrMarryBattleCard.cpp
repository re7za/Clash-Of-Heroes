
#include "DrMarryBattleCard.h"

DrMarryBattleCard::DrMarryBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Dr.Marry");
	heroNameTxt.setCharacterSize(16);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(99, 82, 193));

	//hero health
	healthTxt.setString("hlt 8");

	//hero health
	damageTxt.setString("dmg 2");
}

void DrMarryBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (4).png");
	heroCardSpr.setTexture(heroCardTex);
}

void DrMarryBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}