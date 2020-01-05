
#include "AlphaMan Card.h"

AlphaManCard::AlphaManCard()
{
	setCardSpr();
	setDefaulProperties();

	// hero name
	heroNameTxt.setString("AlphaMan");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 33,
		heroCardSpr.getPosition().y + 15));

	//hero health
	healthTxt.setString("hlt 13");

	//hero health
	damageTxt.setString("dmg 2");
}

void AlphaManCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/AlphaMan Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(30, 40));
}

void AlphaManCard::draw(sf::RenderWindow* window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}