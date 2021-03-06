
#include "Commander Card.h"

CommanderCard::CommanderCard()
{
	cardName = heros::commander;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Commander");
	heroNameTxt.setCharacterSize(18);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 20,
		heroCardSpr.getPosition().y + 20));
	heroNameTxt.setFillColor(sf::Color(174, 32, 49));

	//hero health
	healthTxt.setString("hlt 7");

	//hero health
	damageTxt.setString("dmg 3");
}


void CommanderCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Commander Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(190, 40));
}

void CommanderCard::draw(sf::RenderWindow* window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}