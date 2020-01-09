//grid

#include "Grid.h"

Grid::Grid()
{
	gridTex.loadFromFile("Grid/base/download.png");
	gridSpr.setTexture(gridTex);
	fillTheGrid();
}


void Grid::gridClicked(sf::Vector2i& pos, heros& heroCard)
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			if (pos.x >= tiles.at(i).at(j)->getPosition().x
				&& pos.x < tiles.at(i).at(j)->getPosition().x + tiles.at(i).at(j)->getGlobalBound().width
				&& pos.y >= tiles.at(i).at(j)->getPosition().y
				&& pos.y < tiles.at(i).at(j)->getPosition().y + tiles.at(i).at(j)->getGlobalBound().height)
			{
				//std::cout << heroCard << std::endl;
				heroCard = heros::none;
			}
			else
			{
				heroCard = heros::none;

			}

}

// tiles
void Grid::draw(sf::RenderWindow* window)
{
	window->draw(gridSpr);
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j)->draw(window);
}

sf::Sprite Grid::getGridSpr()
{
	return gridSpr;
}
void Grid::fillTheGrid()
{
	for (std::array<Tile*, 9>& row : tiles)
		for (Tile*& tile : row)
			tile = new Tile();
}

void Grid::setTilesPosition()
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j)->setPosition(sf::Vector2f(this->getPosition().x + (j * (tiles.at(i).at(j)->getGlobalBound().width) + j * 1.5) * this->getScale().x,
				this->getPosition().y + (i * (tiles.at(i).at(j)->getGlobalBound().height) + i * 2) * this->getScale().y));
}

///////////////////////////////////////
// utility functions
void Grid::setTilesScale(const sf::Vector2f& scale)
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j)->setScale(scale);
}

// sfml methodes
void Grid::setFillColor(const sf::Color& color)
{
	gridSpr.setColor(color);
}
void Grid::setPosition(const sf::Vector2f& position)
{
	gridSpr.setPosition(position);
	setTilesPosition();
}
void Grid::setScale(const sf::Vector2f& scale)
{
	gridSpr.setScale(scale);
	setTilesScale(sf::Vector2f(this->getScale().x, this->getScale().y));
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
