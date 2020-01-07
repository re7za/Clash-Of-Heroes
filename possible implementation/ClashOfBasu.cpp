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
	

	sf::Event evnt;
	while (window.isOpen())
	{
		//menuManager.getMousePosition(sf::Mouse::getPosition());

		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::EventType::Closed
				|| evnt.key.code == sf::Keyboard::Escape)
				window.close();

			//sending the mouse events and positions to menuManager
			if (evnt.type == sf::Event::MouseButtonReleased)
				if (evnt.mouseButton.button == sf::Mouse::Left)
					menuManager.rightClickPos(sf::Mouse::getPosition());

			//if (evnt.type == sf::Event::TextEntered)
				
		}
		
		window.clear(sf::Color::White);
		//////////draw your trashes here
		menuManager.displayCurrentMenu(&window);
		////////////////////////////////
		window.display();


	}

	return 0;
}