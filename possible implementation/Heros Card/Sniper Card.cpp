
#include "Sniper Card.h"

SniperCard::SniperCard()
{
	cardName = heros::sniper;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Sniper");
	heroNameTxt.setCharacterSize(24);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 40,
		heroCardSpr.getPosition().y + 15));
	heroNameTxt.setFillColor(sf::Color(255, 198, 1));

	//hero health
	healthTxt.setString("hlt 9");

	//hero health
	damageTxt.setString("dmg 4");
}


void SniperCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Sniper Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(670, 300));
}

void SniperCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}