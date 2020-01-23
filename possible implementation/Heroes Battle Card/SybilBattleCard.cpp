
#include "SybilBattleCard.h"

SybilBattleCard::SybilBattleCard()
{
	cardName = heros::sybil;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Sybil");
	heroNameTxt.setCharacterSize(20);
	heroNameTxt.setFillColor(sf::Color(180, 156, 130));

	//hero health
	healthTxt.setString("hlt 12");

	//hero health
	damageTxt.setString("dmg 2");
}

void SybilBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (11).png");
	heroCardSpr.setTexture(heroCardTex);
}

void SybilBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}