
#include "Leon Card.h"

LeonCard::LeonCard()
{
	cardName = heros::leon;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Leon");
	heroNameTxt.setCharacterSize(20);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 50,
		heroCardSpr.getPosition().y + 13));
	heroNameTxt.setFillColor(sf::Color(245, 96, 48));

	//hero health
	healthTxt.setString("hlt 10");

	//hero health
	damageTxt.setString("dmg 3");
}

void LeonCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Leon Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(830, 40));
}

void LeonCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}