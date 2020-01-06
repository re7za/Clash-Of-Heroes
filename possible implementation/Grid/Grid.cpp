//grid

#include "Grid.h"

Grid::Grid()
{
	gridTex.loadFromFile("Grid/base/download.png");
	gridSpr.setTexture(gridTex);
	setTilesTexArray();
	setDefaultTilesTexturs();
}

sf::Sprite Grid::getGridSpr()
{
	return gridSpr;
}

// mouse events and positions
void Grid::whichTileIsTheMouseOn(sf::Vector2i* pos)
{
	for (std::array<sf::Sprite, 9>& row : tiles)
		for (sf::Sprite& tile : row)
		{

		}
}

// tiles
void Grid::draw(sf::RenderWindow* window)
{
	window->draw(gridSpr);
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			window->draw(tiles.at(i).at(j));
}
void Grid::setHurtTileTexture(us, us)
{

}

// utility functions
void Grid::setTilesTexArray()
{
	tilesTex.at(1).loadFromFile("Grid/tiles/L1.png");
	tilesTex.at(2).loadFromFile("Grid/tiles/L2.png");
}
void Grid::setDefaultTilesTexturs()
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
		{
			tiles.at(i).at(j).setTexture(tilesTex.at(0));
			tiles.at(i).at(j).setPosition(sf::Vector2f(gridSpr.getPosition().x + (i * tilesTex.at(0).getSize().x + i*1.5) * this->getScale().x,
				this->getPosition().y + (j * tilesTex.at(0).getSize().y + j*2)* this->getScale().y));
		}
}
void Grid::setTilesScale(const sf::Vector2f& scale)
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j).setScale(scale.x, scale.y);
}

// sfml methodes
void Grid::setFillColor(const sf::Color& color)
{
	gridSpr.setColor(color);
}
void Grid::setPosition(const sf::Vector2f& position)
{
	gridSpr.setPosition(position);
	setDefaultTilesTexturs();
}
void Grid::setScale(const sf::Vector2f& scale)
{
	gridSpr.setScale(scale);
	setTilesScale(sf::Vector2f(this->getScale().x, this->getScale().y));
	setDefaultTilesTexturs();
}
sf::FloatRect Grid::getGlobalBound()
{
	return gridSpr.getGlobalBounds();
}
const sf::Vector2f& Grid::getOrigin()
{
	return gridSpr.getOrigin();
}
const sf::Vector2f& Grid::getPosition()
{
	return gridSpr.getPosition();
}
const sf::Vector2f& Grid::getScale()
{
	return gridSpr.getScale();
}
