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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			menuManager.rightClickPos(sf::Mouse::getPosition());

		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::EventType::Closed
				|| evnt.key.code == sf::Keyboard::Escape)
				window.close();

			//if (evnt.type == sf::Event::TextEntered)
				


		}
		
		window.clear(sf::Color::White);
		//////////draw your trashes here
		menuManager.displayCurrentMenu(&window);
		playerManager.displayPlayerInfo(&window, menuManager);s
		////////////////////////////////
		window.display();


	}

	return 0;
}