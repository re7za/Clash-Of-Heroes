
#include "Giant Card.h"

GiantCard::GiantCard()
{
	cardName = heros::giant;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("HellBoy");
	heroNameTxt.setCharacterSize(21);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 22,
		heroCardSpr.getPosition().y + 20));
	heroNameTxt.setFillColor(sf::Color(244, 55, 53));

	//hero health
	healthTxt.setString("hlt 16");

	//hero health
	damageTxt.setString("dmg 4");
}


void GiantCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Giant Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(510, 40));
}

void GiantCard::draw(sf::RenderWindow* window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}