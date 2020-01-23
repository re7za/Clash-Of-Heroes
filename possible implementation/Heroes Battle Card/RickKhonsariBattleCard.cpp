
#include "RickKhonsariBattleCard.h"

RickKhonsariBattleCard::RickKhonsariBattleCard()
{
	cardName = heros::alphaMan;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Ramin");
	heroNameTxt.setCharacterSize(24);
	heroNameTxt.setPosition(sf::Vector2f(heroCardSpr.getPosition().x + 30,
		heroCardSpr.getPosition().y + 5));
	heroNameTxt.setFillColor(sf::Color(137, 174, 199));

	//hero health
	healthTxt.setString("hlt 10");

	//hero health
	damageTxt.setString("dmg 3");
}

void RickKhonsariBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (0).png");
	heroCardSpr.setTexture(heroCardTex);
}

void RickKhonsariBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}