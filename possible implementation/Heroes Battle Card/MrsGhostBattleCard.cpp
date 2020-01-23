
#include "MrsGhostBattleCard.h"

MrsGhostBattleCard::MrsGhostBattleCard()
{
	cardName = heros::mrsGhost;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Mrs.Ghost");
	heroNameTxt.setCharacterSize(15);
	heroNameTxt.setFillColor(sf::Color(255, 226, 145));

	//hero health
	healthTxt.setString("hlt 15");

	//hero health
	damageTxt.setString("dmg 3");
}

void MrsGhostBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (8).png");
	heroCardSpr.setTexture(heroCardTex);
}

void MrsGhostBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}