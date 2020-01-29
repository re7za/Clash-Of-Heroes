#include "Panel.h"

Panel::Panel()
{
	txtFont.loadFromFile("Font/fighting spirit TBS.ttf");
	txt.setFont(txtFont);
	txt.setCharacterSize(30);
	txt.setFillColor(sf::Color::White);
	txt.setString("new text");
}

Panel::Panel(std::string str, us characterSize)
{
	txtFont.loadFromFile("Font/fighting spirit TBS.ttf");
	txt.setFont(txtFont);
	txt.setCharacterSize(characterSize);
	txt.setString(str);
}

void Panel::draw(sf::RenderWindow* window)
{
	window->draw(txt);
}

// sfml text function

void Panel::setCharacterSize(const us& size)
{
	txt.setCharacterSize(size);
}
void Panel::setFillColor(const sf::Color& color)
{
	txt.setFillColor(color);
}
void Panel::setFont(const sf::Font& font)
{
	txt.setFont(font);
}
void Panel::setOutlineColor(const sf::Color& color)
{
	txt.setOutlineColor(color);
}
void Panel::setOutlineThinkness(float thinkness)
{
	txt.setOutlineThickness(thinkness);
}
void Panel::setPosition(const sf::Vector2f& pos)
{
	txt.setPosition(pos);
}
void Panel::setString(const std::string& str)
{
	txt.setString(str);
}
void Panel::setStyle(sf::Uint32 style)
{
	txt.setStyle(style);
}
void Panel::setOrigin(const sf::Vector2f& pos)
{
	txt.setOrigin(pos);
}
us Panel::getCharacterSize()
{
	return txt.getCharacterSize();
}
sf::Color Panel::getFillColor()
{
	return txt.getFillColor();
}
sf::FloatRect Panel::getGlobalBounds()
{
	return txt.getGlobalBounds();
}
sf::Vector2f Panel::getPosition()
{
	return txt.getPosition();
}

void Panel::setOrginalFillColor(const sf::Color& color)
{
	orginalColor = color;
}

sf::Color Panel::getOrginalFillColor()
{
	return orginalColor;
}


