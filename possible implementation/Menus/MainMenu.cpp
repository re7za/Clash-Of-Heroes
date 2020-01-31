#include "MainMenu.h"

MainMenu::MainMenu()
{
	// set the name and others
	menuName = menuType::mainMenu;
	previousMenu = menuType::none;

	// background
	backgroundTex.loadFromFile("Menus/background/MainMenu.jpg");
	menuSpr.setTexture(backgroundTex);
	// strip
	stripTex.loadFromFile("Menus/background/strips/do-alpha2.png");
	stripSpr.setTexture(stripTex);
	stripSpr.setPosition(sf::Vector2f(100, 0));

	////////////////////// clash of heroes logo
	gameLabelFont.loadFromFile("Font/fighting spirit TBS_bold.ttf");
	// Clash part
	clash.setFont(gameLabelFont);
	clash.setString("Clash");
	clash.setCharacterSize(90);
	clash.setFillColor(sf::Color(30, 30, 30, 255));
	clash.setOutlineThickness(4);
	clash.setOutlineColor(sf::Color(190, 43, 61, 255));
	clash.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - clash.getGlobalBounds().width / 2, 40));

	// Of part
	of.setFont(gameLabelFont);
	of.setString("Of");
	of.setCharacterSize(70);
	of.setFillColor(sf::Color(30, 30, 30, 255));
	of.setOutlineThickness(4);
	of.setOutlineColor(sf::Color(190, 43, 61, 255));
	of.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - of.getGlobalBounds().width / 2, 125));

	// Heroes part
	heroes.setFont(gameLabelFont);
	heroes.setString("Heroes");
	heroes.setCharacterSize(130);
	heroes.setFillColor(sf::Color(30, 30, 30, 255));
	heroes.setOutlineThickness(4);
	heroes.setOutlineColor(sf::Color(190, 43, 61, 255));
	heroes.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - heroes.getGlobalBounds().width / 2, 160));

	//////////////// buttons
	// start Btn
	startBtn.setString("NEW GAME");
	startBtn.setCharacterSize(50);
	startBtn.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - startBtn.getGlobalBound().width / 2, 450));
	
	// about Btn
	aboutBtn.setString("ABOUT");
	aboutBtn.setCharacterSize(40);
	aboutBtn.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - aboutBtn.getGlobalBound().width / 2, 540));

	// quit Btn
	quitBtn.setString("QUIT");
	quitBtn.setCharacterSize(40);
	quitBtn.setPosition(sf::Vector2f(stripSpr.getPosition().x
		+ stripSpr.getGlobalBounds().width / 2 - quitBtn.getGlobalBound().width / 2, 610));

}

void MainMenu::display(sf::RenderWindow* window)
{
	// get the window just for quit
	this->window = window;

	mouseHover(window);
	// background
	window->draw(menuSpr);

	// strip
	window->draw(stripSpr);

	// clash of heroes logo
	window->draw(clash);
	window->draw(of);
	window->draw(heroes);

	// buttons
	startBtn.draw(window);
	aboutBtn.draw(window);
	quitBtn.draw(window);

}

void MainMenu::mouseHover(sf::RenderWindow* window)
{
	startBtn.onMouseOver();
	aboutBtn.onMouseOver();
	quitBtn.onMouseOver();
}

void MainMenu::click(sf::Vector2i& pos, menuType& currentMenu)
{
	// start the new game
	if (startBtn.getGlobalBound().contains(sf::Vector2f(pos)))
		currentMenu = menuType::heroSelection;

	// quit button
	if (quitBtn.getGlobalBound().contains(sf::Vector2f(pos)))
		window->close();
}
