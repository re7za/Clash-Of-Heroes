
#include "DrMarryBattleCard.h"

DrMarryBattleCard::DrMarryBattleCard()
{
	cardName = heros::drMarry;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Dr.Marry");
	heroNameTxt.setCharacterSize(16);
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