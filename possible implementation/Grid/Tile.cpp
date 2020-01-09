
#include "Tile.h"

Tile::Tile()
{
	tileTex.loadFromFile("Grid/tiles/L0.png");
	tileSpr.setTexture(tileTex);
	tileSpr.getGlobalBounds();
	// set default color : opacity = 0
	tileSpr.setColor(sf::Color(100, 0, 180, 0));
	tileOrginalColor = tileSpr.getColor();
}


void Tile::tileClicked()
{

}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(tileSpr);
}

// sfml methodes
void Tile::setFillColor(const sf::Color& color)
{
	tileSpr.setColor(color);
}
void Tile::setPosition(const sf::Vector2f& position)
{
	tileSpr.setPosition(position);
}
void Tile::setScale(const sf::Vector2f& scale)
{
	tileSpr.setScale(scale);
}
sf::FloatRect Tile::getGlobalBound()
{
	return tileSpr.getGlobalBounds();
}
const sf::Vector2f& Tile::getOrigin()
{
	return tileSpr.getOrigin();
}
const sf::Vector2f& Tile::getPosition()
{
	return tileSpr.getPosition();
}
const sf::Vector2f& Tile::getScale()
{
	return tileSpr.getScale();
}
