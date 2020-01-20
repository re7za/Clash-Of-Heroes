
#include "Button.h"

Button::Button()
{
	btnFont.loadFromFile("Font/Button.otf");
	btnTxt.setFont(btnFont);
	btnTxt.setFillColor(sf::Color(230, 230, 230, 200));
	this->setCharacterSize(50);

}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(btnTxt);
}
void Button::onMouseOver()
{
	if (sf::Mouse::getPosition().x > btnTxt.getPosition().x
		&& sf::Mouse::getPosition().x < btnTxt.getPosition().x + btnTxt.getLocalBounds().width
		&& sf::Mouse::getPosition().y > btnTxt.getGlobalBounds().top
		&& sf::Mouse::getPosition().y < btnTxt.getGlobalBounds().top + btnTxt.getLocalBounds().height)
	{
		btnTxt.setFillColor(sf::Color::White);
	}
	else
	{
		btnTxt.setFillColor(sf::Color(230, 230, 230, 200));
	}
}



void Button::setFillColor(const sf::Color& color)
{
	btnTxt.setFillColor(color);
}
void Button::setPosition(const sf::Vector2f& position)
{
	btnTxt.setPosition(position);
}
void Button::setCharacterSize(unsigned short size)
{
	btnTxt.setCharacterSize(size);
}
void Button::setString(const sf::String& string)
{
	btnTxt.setString(string);
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

