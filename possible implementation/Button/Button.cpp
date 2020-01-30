
#include "Button.h"

Button::Button()
{
	btnFont.loadFromFile("Font/FFF_Tusj.ttf");
	btnTxt.setFont(btnFont);
	btnTxt.setFillColor(sf::Color(230, 230, 230, 255));
	this->setCharacterSize(55);

	// rect
	//btnRect.setFillColor(sf::Color(5, 5, 5, 150));
	//btnRect.setPosition(sf::Vector2f(getPosition()));
	//btnRect.setSize(sf::Vector2f(200, 200));
}

void Button::draw(sf::RenderWindow* window)
{
	//window->draw(btnRect);
	window->draw(btnTxt);
}
void Button::onMouseOver()
{
	if (btnTxt.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition())))
	{
		btnTxt.setFillColor(sf::Color(220, 73, 91, 255));
		//btnRect.setFillColor(sf::Color(btnRect.getFillColor().r, btnRect.getFillColor().g, btnRect.getFillColor().b, 220));
	}
	else
	{
		btnTxt.setFillColor(sf::Color(220, 220, 220, 240));
		//btnRect.setFillColor(sf::Color(btnRect.getFillColor().r, btnRect.getFillColor().g, btnRect.getFillColor().b, 150));
	}
}


void Button::setFillColor(const sf::Color& color)
{
	btnTxt.setFillColor(color);
}
void Button::setPosition(const sf::Vector2f& position)
{
	btnTxt.setPosition(position);
	//rect
	//btnRect.setPosition(sf::Vector2f(getPosition().x, getPosition().y + 8));
}
void Button::setCharacterSize(unsigned short size)
{
	btnTxt.setCharacterSize(size);
}
void Button::setString(const sf::String& string)
{
	btnTxt.setString(string);
}
void Button::setFont(const sf::Font& font)
{
	btnTxt.setFont(font);
}
sf::FloatRect Button::getGlobalBound()
{
	return btnTxt.getGlobalBounds();
}
const sf::Vector2f& Button::getPosition()
{
	return btnTxt.getPosition();
}
unsigned short Button::getCharacterSize()
{
	return btnTxt.getCharacterSize();
}

// rect
void Button::setRectSize(const sf::Vector2f& size)
{
	btnRect.setSize(size);
}
void Button::setRectColor(const sf::Color& color)
{
	btnRect.setFillColor(color);
}

