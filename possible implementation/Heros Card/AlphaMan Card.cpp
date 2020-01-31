
#include "AlphaMan Card.h"

AlphaManCard::AlphaManCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();
	
	// hero name
	heroNameTxt.setString("AlphaMan");
	heroNameTxt.setCharacterSize(22);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 20,
		heroCardSpr.getPosition().y + 20));
		heroNameTxt.setFillColor(sf::Color(23, 152, 255));

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