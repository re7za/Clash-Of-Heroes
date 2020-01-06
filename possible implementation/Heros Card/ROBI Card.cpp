
#include "ROBI Card.h"

ROBICard::ROBICard()
{
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();
	
	// hero name
	heroNameTxt.setString("ROBI");
	heroNameTxt.setCharacterSize(20);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 45,
		heroCardSpr.getPosition().y + 15));

	//hero health
	healthTxt.setString("hlt 9");

	//hero health
	damageTxt.setString("dmg 4");
}


void ROBICard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/ROBI Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(510, 300));
}

void ROBICard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}