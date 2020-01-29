#include "Timer.h"

Timer::Timer()
{
	clockFont.loadFromFile("Font/textbox.ttf");
	timerPanel.setFont(clockFont);
	timerPanel.setCharacterSize(40);
	timerPanel.setString("00 : 00");
}

void Timer::draw(sf::RenderWindow* window)
{
	updateTimerPanel();
	timerPanel.draw(window);
}

// sfml clock methodes
sf::Time Timer::getElapsedTime()
{
	return clk.getElapsedTime();
}
sf::Time Timer::restart()
{
	return clk.restart();
}


// sfml panel function
void Timer::setCharacterSize(const us& size)
{
	timerPanel.setCharacterSize(size);
}
void Timer::setFillColor(const sf::Color& color)
{
	timerPanel.setFillColor(color);
}
void Timer::setFont(const sf::Font& font)
{
	timerPanel.setFont(font);
}
void Timer::setOutlineColor(const sf::Color& color)
{
	timerPanel.setOutlineColor(color);
}
void Timer::setOutlineThinkness(float thinkness)
{
	timerPanel.setOutlineThinkness(thinkness);
}
void Timer::setPosition(const sf::Vector2f& pos)
{
	timerPanel.setPosition(pos);
}
void Timer::setString(const std::string& str)
{
	timerPanel.setString(str);
}
void Timer::setStyle(sf::Uint32 style)
{
	timerPanel.setStyle(style);
}
us Timer::getCharacterSize()
{
	return timerPanel.getCharacterSize();
}
sf::Color Timer::getFillColor()
{
	return timerPanel.getFillColor();
}
sf::FloatRect Timer::getGlobalBounds()
{
	return timerPanel.getGlobalBounds();
}
sf::Vector2f Timer::getPosition()
{
	return timerPanel.getPosition();
}

void Timer::Start()
{
	if (start == false)
	{
		clk.restart();
		start = true;
	}
}
void Timer::updateTimerPanel()
{
	if (start == true)
	{
		unsigned short elapsedTime = clk.getElapsedTime().asSeconds();
		Template.minute = elapsedTime / 60;
		Template.second = elapsedTime % 60;

		if (Template.minute < 10)
		{
			if (Template.second < 10)
				timerPanel.setString("0" + std::to_string(Template.minute) + " : " + "0" + std::to_string(Template.second));
			else
				timerPanel.setString("0" + std::to_string(Template.minute) + " : " + std::to_string(Template.second));
		}
		else
		{
			if (Template.second < 10)
				timerPanel.setString(std::to_string(Template.minute) + " : " + "0" + std::to_string(Template.second));
			else
				timerPanel.setString(std::to_string(Template.minute) + " : " + std::to_string(Template.second));
		}
	}
	
}

