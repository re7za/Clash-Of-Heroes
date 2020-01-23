
#include "Sybil Card.h"

SybilCard::SybilCard()
{
	cardName = heros::sybil;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Sybil");
	heroNameTxt.setCharacterSize(20);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 48,
		heroCardSpr.getPosition().y + 15));
	heroNameTxt.setFillColor(sf::Color(180, 156, 130));

	//hero health
	healthTxt.setString("hlt 12");

	//hero health
	damageTxt.setString("dmg 2");
}


void SybilCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Sybil Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(830, 300));
}

void SybilCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}