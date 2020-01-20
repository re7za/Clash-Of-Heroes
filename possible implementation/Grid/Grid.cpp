//grid

#include "Grid.h"

Grid::Grid()
{
	gridTex.loadFromFile("Grid/base/download.png");
	gridSpr.setTexture(gridTex);
	fillTheGrid();
	setFillColor(sf::Color(80, 0, 20));
}


void Grid::gridClicked(const sf::Vector2i& pos, PlayerManager& playerManager, heros& heroCard)
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			if (pos.x >= tiles.at(i).at(j)->getPosition().x
				&& pos.x < tiles.at(i).at(j)->getPosition().x + tiles.at(i).at(j)->getGlobalBound().width
				&& pos.y >= tiles.at(i).at(j)->getPosition().y
				&& pos.y < tiles.at(i).at(j)->getPosition().y + tiles.at(i).at(j)->getGlobalBound().height)
			{
				// checking for PlayerHeroSize


				// delete and erase this tile
				if (heroCard == heros::none)
				{
					if (tiles.at(i).at(j)->IsHeroSpr())
					{
						clearTile(tiles.at(i).at(j));

					}
					//std::cout << heroCard << " if" << std::endl;
				}
				else
				{
					// update the grid
					//std::cout << heroCard << " else" << std::endl;
					if (tiles.at(i).at(j)->IsHeroSpr())
						clearTile(tiles.at(i).at(j));

					tiles.at(i).at(j)->setHeroSpr(heroCard);
				}

				// update player vector
				setThePlayerHerosVec(playerManager, heroCard);

				// the last part
				heroCard = heros::none;
			}

}

void Grid::clearTile(Tile*& tile)
{
	tile->removeHeroSpr();
}

void Grid::setThePlayerHerosVec(PlayerManager& playerManager, heros& heroCard)
{
	switch (heroCard)
	{
	case heros::mrsGhost:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new MrsGhost());
		break;
	}
	case heros::robi:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new ROBI());
		break;
	}
	case heros::leon:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Leon());
		break;
	}
	case heros::drMarry:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new DrMarry());
		break;
	}
	case heros::sniper:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Sniper());
		break;
	}
	case heros::kratos:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Kratos());
		break;
	}
	case heros::giant:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Giant());
		break;
	}
	case heros::alphaMan:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new AlphaMan());
		break;
	}
	case heros::professor:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Professor());
		break;
	}
	case heros::commander:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Commander());
		break;
	}
	case heros::rickKhonsari:
	{
		playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new RickKhonsari());
		break;
	}
	case heros::sybil:
	{
		//playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))->playerHerosVec.push_back(new Sybil());
		break;
	}
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
