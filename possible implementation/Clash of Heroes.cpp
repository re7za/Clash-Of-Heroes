//Clash Of BASU

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Menus/MenuManager.h"
#include "Player/PlayerManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
		sf::VideoMode::getDesktopMode().height), "Clash Of BASU", sf::Style::Fullscreen);
	
	srand(static_cast<size_t>(time(NULL)));
	MenuManager menuManager;
	

	// its necessary for clicking process.. leave it alone
	bool LeftClickPression = false;
	sf::Vector2i mousePosAtPression;

	sf::Event evnt;
	while (window.isOpen())
	{
		// menuManager.getMousePosition(sf::Mouse::getPosition());

		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::EventType::Closed
				|| evnt.key.code == sf::Keyboard::Escape)
				window.close();

			// sending the mouse events and positions to menuManager
			if (evnt.type == sf::Event::MouseButtonPressed)
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					LeftClickPression = true;
					mousePosAtPression = sf::Mouse::getPosition();
				}
			if (evnt.type == sf::Event::MouseButtonReleased)
				if (evnt.mouseButton.button == sf::Mouse::Left)
					if (LeftClickPression == true)
						if (mousePosAtPression == sf::Mouse::getPosition())
						{
							LeftClickPression = false;
							menuManager.clickPos(sf::Mouse::getPosition());
						}

			//if (evnt.type == sf::Event::TextEntered)
				
		}
		
		window.clear();
		///////// draw your trashes here
		menuManager.displayCurrentMenu(&window);
		////////////////////////////////
		window.display();


	}

	return 0;
}