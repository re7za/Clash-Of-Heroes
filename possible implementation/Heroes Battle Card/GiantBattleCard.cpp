
#include "GiantBattleCard.h"

GiantBattleCard::GiantBattleCard()
{
	cardName = heros::giant;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Giant");
	heroNameTxt.setCharacterSize(22);
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

void GiantBattleCard::anotherClick()
{
	if (secondClick == 0)
		secondClick++;
	else if (secondClick == 1)
		secondClick++;
	else
		secondClick = 0;
}

us GiantBattleCard::getTheClickSituation()
{
	return secondClick;
}

void GiantBattleCard::resetTheClickSituation()
{
	secondClick = 0;
}
