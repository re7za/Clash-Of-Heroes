
#include "CommanderBattleCard.h"

CommanderBattleCard::CommanderBattleCard()
{
	cardName = heros::commander;

	// cardSpr
	setCardSpr();
	setDefaulProperties();
	SprOrginalColor = heroCardSpr.getColor();

	// hero name
	heroNameTxt.setString("Commander");
	heroNameTxt.setCharacterSize(15);
	heroNameTxt.setFillColor(sf::Color(174, 32, 49));

	//hero health
	healthTxt.setString("hlt 7");

	//hero health
	damageTxt.setString("dmg 3");
}

void CommanderBattleCard::setCardSpr()
{
	heroCardTex.loadFromFile("Heroes Battle Card/cards/image (2).png");
	heroCardSpr.setTexture(heroCardTex);
}

void CommanderBattleCard::draw(sf::RenderWindow * window)
{
	window->draw(heroCardSpr);
	window->draw(heroNameTxt);
	window->draw(healthTxt);
	window->draw(damageTxt);
}

bool CommanderBattleCard::getSpecialPower()
{
	return specialPower;
}

void CommanderBattleCard::ChangeSpecialPower()
{
	if (specialPower == true)
		specialPower = false;
	else
		specialPower = true;
}

