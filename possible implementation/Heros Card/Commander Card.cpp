
#include "Commander Card.h"

CommanderCard::CommanderCard()
{
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Commander");
	heroNameTxt.setCharacterSize(16);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 33,
		heroCardSpr.getPosition().y + 15));

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