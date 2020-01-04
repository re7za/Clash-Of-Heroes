#pragma once

#ifndef GRID_H
#define GTID_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"
#include <array>

enum class tileType { L1, L2, L3 };

class Grid
{
public:
	Grid();
	sf::Sprite getGridSpr();

	// tiles
	void setHurtTileTexture(us, us);
	void draw(sf::RenderWindow* window);

	// sfml methodes
	void setFillColor(const sf::Color&);
	void setPosition(const sf::Vector2f&);
	void setScale(const sf::Vector2f&);
	sf::FloatRect getGlobalBound();
	const sf::Vector2f& getOrigin();
	const sf::Vector2f& getPosition();
	const sf::Vector2f& getScale();


private:
	//utility functions
	void setTilesTexArray();
	void setDefaultTilesTexturs();
	void setTilesScale(const sf::Vector2f&);

	sf::Texture gridTex;
	sf::Sprite gridSpr;
	std::array<std::array<sf::Sprite, 9>, 9> tiles;
	std::array<sf::Texture, 3> tilesTex;
	tileType tileStatus = tileType::L1;
};


#endif