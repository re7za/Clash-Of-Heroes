#pragma once

#ifndef TIMER_H
#define TIMER_H

#include "SFML/Graphics.hpp"
#include "../Panel/Panel.h"
#include <iomanip>

struct timeT
{
	unsigned short minute;
	unsigned short second;
};

class Timer
{
public:
	Timer();

	void draw(sf::RenderWindow*);

	// sfml clock methodes
	sf::Time getElapsedTime();
	sf::Time restart();

	// sfml panel function
	// setter
	void setCharacterSize(const us&);
	void setFillColor(const sf::Color&);
	void setFont(const sf::Font&);
	void setOutlineColor(const sf::Color&);
	void setOutlineThinkness(float thinkness);
	void setPosition(const sf::Vector2f&);
	void setString(const std::string&);
	void setStyle(sf::Uint32 style);
	// getter
	us getCharacterSize();
	sf::Color getFillColor();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();

	void Start();

private:

	// clock
	sf::Clock clk;
	void updateTimerPanel();
	timeT Template;

	bool start = false;

	// panel
	Panel timerPanel;
	sf::Font clockFont;



};

#endif // !TIMER_H
