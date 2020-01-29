
#include "KratosBattleCard.h"

KratosBattleCard::KratosBattleCard()
{
	cardName = heros::kratos;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Kratos");
	heroNameTxt.setCharacterSize(22);
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

void KratosBattleCard::anotherClick()
{
	if (key == 1)
	{
		if (secondClick == 0)
			secondClick++;
		else if (secondClick == 1)
			secondClick++;
		else
			secondClick = 0;
	}
}

us KratosBattleCard::getTheClickSituation()
{
	return secondClick;
}

void KratosBattleCard::resetTheClickSituation()
{
	secondClick = 0;
}

void KratosBattleCard::usingKey()
{
	key = 0;
}

