#pragma once

#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"

enum class tileType { L1, L2, L3 };

class Tile
{
public:
	Tile();

	// tiles
	void tileClicked();
	//void setHurtTile();
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
	sf::Texture tileTex;
	sf::Sprite tileSpr;

	sf::Color tileOrginalColor;

	tileType tileStatus = tileType::L1;
};


#endif