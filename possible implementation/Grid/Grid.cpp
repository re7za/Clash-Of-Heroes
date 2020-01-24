//grid

#include "Grid.h"

Grid::Grid()
{
	gridTex.loadFromFile("Grid/base/download.png");
	gridSpr.setTexture(gridTex);
	fillTheGrid();
	setFillColor(sf::Color(80, 0, 20));

}


void Grid::SelectionClicked(const sf::Vector2i& pos, PlayerManager* playerManager, heros& heroCard)
{
		for (us i = 0; i < 9; i++)			// row
			for (us j = 0; j < 9; j++)		// column
				if (tiles.at(i).at(j)->getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
				{
					// set or remove this tile
					if (heroCard == heros::none)		// remove
					{
						if (tiles.at(i).at(j)->IsHeroSpr())
							clearTileAndHero(tiles.at(i).at(j), playerManager);
					}
					else								// set
					{
						// preventing redefining a hero
						if (!playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))
							->isHeroExistInVec(heroCard))
						{
							if (!playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))
								->isPlayerHeroVecFull() || tiles.at(i).at(j)->IsHeroSpr())		// preventing defining more than 5 hero
							{
								if (tiles.at(i).at(j)->IsHeroSpr())
									clearTileAndHero(tiles.at(i).at(j), playerManager);

								// update the grid
								tiles.at(i).at(j)->setHeroSpr(heroCard);

								// update player vector
								setThePlayerHerosVec(playerManager, heroCard, sf::Vector2i(i, j));
							}
						}
						/*else
							std::cout << "you can't select a hero twice!!!" << std::endl;

						if (playerManager.playerArr.at(static_cast<us> (playerManager.getTheTurn()))
							->playerHerosVec.size() == 5)
						{
							std::cout << " you can't select more than 5 hero!!!" << std::endl;
						}*/
					}

					// the last part
					heroCard = heros::none;
					return;
				}		
}

void Grid::battlefieldClicked(const sf::Vector2i& pos, PlayerManager* playerManager, heros heroIcon)
{
	for (us i = 0; i < 9; i++)			// row
		for (us j = 0; j < 9; j++)		// column
			if (tiles.at(i).at(j)->getGlobalBound().contains(static_cast<sf::Vector2f>(pos)))
			{
				playerManager->changeTheTurn();
			}
}

void Grid::plantingHeroes(const std::vector<Hero*>& heroesVec)
{
	// clean the all tiles spr
	clearAllTiles();

	// planting the hero.. its spr
	for (Hero* hero : heroesVec)
		if (!hero->isHidden())
		{
			tiles.at(hero->getHeroPosition().x).at(hero->getHeroPosition().y)->setHeroSpr(hero->getId());
			tiles.at(hero->getHeroPosition().x).at(hero->getHeroPosition().y)->setScale(this->getScale());
		}
		else
			tiles.at(hero->getHeroPosition().x).at(hero->getHeroPosition().y)->removeHeroSpr();
}

void Grid::clearAllTiles()
{
	for (std::array<Tile*, 9>& row : tiles)
		for (Tile*& tile : row)
			if (tile->IsHeroSpr())
				tile->removeHeroSpr();
}

void Grid::clearTileAndHero(Tile*& tile ,PlayerManager* playerManager)
{
	// graphic side
	tile->removeHeroSpr();

	// logic side
	playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))
		->removeHero(tile->getHeroCardName());
}

void Grid::setThePlayerHerosVec(PlayerManager* playerManager, heros& heroCard,const sf::Vector2i& pos)
{
	switch (heroCard)
	{
	case heros::mrsGhost:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new MrsGhost(pos));
		break;
	}
	case heros::robi:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new ROBI(pos));
		break;
	}
	case heros::leon:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Leon(pos));
		break;
	}
	case heros::drMarry:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new DrMarry(pos));
		break;
	}
	case heros::sniper:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Sniper(pos));
		break;
	}
	case heros::kratos:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Kratos(pos));
		break;
	}
	case heros::giant:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Giant(pos));
		break;
	}
	case heros::alphaMan:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new AlphaMan(pos));
		break;
	}
	case heros::professor:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Professor(pos));
		break;
	}
	case heros::commander:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Commander(pos));
		break;
	}
	case heros::rickKhonsari:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new RickKhonsari(pos));
		break;
	}
	case heros::sybil:
	{
		playerManager->playerArr.at(static_cast<us> (playerManager->getTheTurn()))->playerHerosVec.push_back(new Sybil(pos));
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

///////////////////////////////////////
// utility functions
void Grid::setTilesPosition()
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j)->setPosition(sf::Vector2f(this->getPosition().x + (j * (tiles.at(i).at(j)->getGlobalBound().width + 1.7 * this->getScale().x)) ,
				this->getPosition().y + (i * (tiles.at(i).at(j)->getGlobalBound().height + 2 * this->getScale().y))));
}
void Grid::setTilesScale(const sf::Vector2f& scale)
{
	for (us i = 0; i < 9; i++)
		for (us j = 0; j < 9; j++)
			tiles.at(i).at(j)->setScale(scale);

	// update the position
	setTilesPosition();
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
	setTilesScale(scale);
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
const sf::Color& Grid::getColor()
{
	return gridSpr.getColor();
}
