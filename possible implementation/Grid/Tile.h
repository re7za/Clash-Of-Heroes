#pragma once

#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics.hpp"
#include "../generalDef.h"
#include "iostream"

enum class tileType { L1, L2, L3 };

class Tile
{
public:
	Tile();

	// tiles
	void clicked();
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

	// set and remove hero and the others
	void setHeroSpr(const heros&);
	void removeHeroSpr();
	void setHeroTex(bool);
	bool IsHeroSpr();
	bool IsheroTex();
	// logic side
	heros getHeroCardName();
	

private:
	// area modes
	sf::Texture tileModTex;
	sf::Sprite tileModSpr;
	sf::Color tileModOrginalColor;
	tileType tileModStatus = tileType::L1;

	// area heroSpr
	bool isHeroSpr = false;
	bool isHeroTex = false;
	heros currentHero = heros::none;
	sf::Texture* heroTex;
	sf::Sprite* heroSpr;
	
};


#endif