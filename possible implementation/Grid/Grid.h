#pragma once

#ifndef GRID_H
#define GTID_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"
#include "Tile.h"
#include <array>
#include <iostream>

class Grid
{
public:
	Grid();

	// fill the grid by tiles
	void fillTheGrid();
	void setTilesPosition();

	// draw
	void draw(sf::RenderWindow*);

	// click on tiles
	void gridClicked(sf::Vector2i&);

	// sfml 
	sf::Sprite getGridSpr();
	void setFillColor(const sf::Color&);
	void setPosition(const sf::Vector2f&);
	void setScale(const sf::Vector2f&);
	sf::FloatRect getGlobalBound();
	const sf::Vector2f& getOrigin();
	const sf::Vector2f& getPosition();
	const sf::Vector2f& getScale();


private:
	//utility functions
	void setTilesScale(const sf::Vector2f&);

	sf::Texture gridTex;
	sf::Sprite gridSpr;
	std::array<std::array<Tile*, 9>, 9> tiles;
};


#endif