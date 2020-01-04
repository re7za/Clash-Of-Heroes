//Clash Of BASU

#include <iostream>
#include <sfml/Graphics.hpp>
#include "Menus/MenuManager.h"
#include "Player/PlayerManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
		sf::VideoMode::getDesktopMode().height), "Clash Of BASU", sf::Style::Fullscreen);
	
	MenuManager menuManager;
	PlayerManager playerManager;

	
	sf::Event evnt;
	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::EventType::Closed
				|| evnt.key.code == sf::Keyboard::Escape)
				window.close();
		}
		
		window.clear(sf::Color::White);
		//////////draw
		menuManager.displayCurrentMenu(&window);
		playerManager.displayPlayerInfo(&window, menuManager);
		//////////////
		window.display();


	}

	return 0;
}