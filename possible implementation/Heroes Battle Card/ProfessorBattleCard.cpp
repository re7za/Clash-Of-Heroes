
#include "ProfessorBattleCard.h"

ProfessorBattleCard::ProfessorBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Professor");
	heroNameTxt.setCharacterSize(15);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(185, 214, 124));

	//hero health
	healthTxt.setString("hlt 11");

	//hero health
	damageTxt.setString("dmg 3");
}

void ProfessorBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (7).png");
	heroCardSpr.setTexture(heroCardTex);
}

void ProfessorBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}