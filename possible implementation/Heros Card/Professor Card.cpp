
#include "Professor Card.h"

ProfessorCard::ProfessorCard()
{
	setCardSpr();
	setDefaulProperties();

	// hero name
	heroNameTxt.setString("Professor");
	heroNameTxt.setCharacterSize(15);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 37,
		heroCardSpr.getPosition().y + 15));

	//hero health
	healthTxt.setString("hlt 11");

	//hero health
	damageTxt.setString("dmg 3");
}


void ProfessorCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heros Card/in frame/Professor Card.png");
	heroCardSpr.setTexture(heroCardTex);
	heroCardSpr.setPosition(sf::Vector2f(190, 300));
}

void ProfessorCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}