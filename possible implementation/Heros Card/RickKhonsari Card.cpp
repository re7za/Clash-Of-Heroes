
#include "RickKhonsari Card.h"

RickKhonsariCard::RickKhonsariCard()
{
	cardName = heros::rickKhonsari;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Ramin");
	heroNameTxt.setCharacterSize(20);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 48,
		heroCardSpr.getPosition().y + 15));
	heroNameTxt.setFillColor(sf::Color(137, 174, 199));

	//hero health
	healthTxt.setString("hlt 10");

	//hero health
	damageTxt.setString("dmg 3");
}


void RickKhonsariCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/RickKhonsari Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(350, 300));
}

void RickKhonsariCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}