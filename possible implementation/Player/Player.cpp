
#include "Player.h"

Player::Player()
{
	// set selectionGrid
	grid.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 + 100,
		sf::VideoMode::getDesktopMode().height * 1 / 3 - 30));

}

void Player::display(sf::RenderWindow* window)
{
		grid.draw(window);
}
