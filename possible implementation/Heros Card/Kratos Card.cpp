
#include "Kratos Card.h"

KratosCard::KratosCard()
{
	cardName = heros::kratos;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Kratos");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 40,
		heroCardSpr.getPosition().y + 15));
	heroNameTxt.setFillColor(sf::Color(31, 170, 34));

	//hero health
	healthTxt.setString("hlt 15");

	//hero health
	damageTxt.setString("dmg 3");
}

void KratosCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Kratos Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(670, 40));
}

void KratosCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}