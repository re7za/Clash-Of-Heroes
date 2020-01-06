
#include "MrsGhost Card.h"

MrsGhostCard::MrsGhostCard()
{
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Mrs.Ghost");
	heroNameTxt.setCharacterSize(15);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 37,
		heroCardSpr.getPosition().y + 15));

	//hero health
	healthTxt.setString("hlt 15");

	//hero health
	damageTxt.setString("dmg 3");
}


void MrsGhostCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/MrsGhost Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(30, 300));
}

void MrsGhostCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}