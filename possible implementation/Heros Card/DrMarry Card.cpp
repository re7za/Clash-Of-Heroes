
#include "DrMarry Card.h"

DrMarryCard::DrMarryCard()
{
	cardName = heros::drMarry;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Dr.Marry");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 36,
		heroCardSpr.getPosition().y + 15));
	heroNameTxt.setFillColor(sf::Color(99 + 40, 82 + 40, 193 + 40));
	
	//hero health
	healthTxt.setString("hlt 8");

	//hero health
	damageTxt.setString("dmg 2");
}


void DrMarryCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/DrMarry Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(350, 40));
}

void DrMarryCard::draw(sf::RenderWindow* window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}