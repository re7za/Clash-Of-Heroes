#include "Widget.h"

Widget::Widget()
{
	// background rect
	backgroundRect.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width,
		sf::VideoMode::getDesktopMode().height));
	backgroundRect.setPosition(sf::Vector2f(0, 0));
	backgroundRect.setFillColor(sf::Color(0, 0, 0, 75));
	
	// message rect
	backTex.loadFromFile("Widget/messageRect/base.png");
	backSpr.setTexture(backTex);
	backSpr.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2
		- backSpr.getGlobalBounds().width / 2 , 300));
	backSpr.setColor(sf::Color(backSpr.getColor().r, backSpr.getColor().g,
		backSpr.getColor().b, 230));

	// message
	messageFont.loadFromFile("Font/Button.otf");
	messageTxt.setFont(messageFont);
	messageTxt.setFillColor(sf::Color::White);
	messageTxt.setString("your meesage");
	messageTxt.setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width / 2 - messageTxt.getGlobalBounds().width / 2,
		backSpr.getPosition().y + 50));	
}

Widget::Widget(const std::string& str)
	:Widget()
{
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(40);
	buttonVec.at(0)->setString(str);
	buttonVec.at(0)->setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width / 2 - buttonVec.at(0)->getGlobalBound().width / 2,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));
}

Widget::Widget(const std::string& str1, const std::string& str2)
	:Widget()
{
	// btn1
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(40);
	buttonVec.at(0)->setString(str1);
	buttonVec.at(0)->setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width / 3 - buttonVec.at(0)->getGlobalBound().width / 2,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));

	// btn2
	buttonVec.push_back(new Button());
	buttonVec.at(1)->setCharacterSize(40);
	buttonVec.at(1)->setString(str2);
	buttonVec.at(1)->setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width * 2/3 - buttonVec.at(1)->getGlobalBound().width / 2,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));

}

Widget::Widget(const std::string& str1, const std::string& str2, const std::string& str3)
	:Widget()
{
	// btn1
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(30);
	buttonVec.at(0)->setString(str1);
	buttonVec.at(0)->setPosition(sf::Vector2f(backSpr.getPosition().x + 35,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));

	// btn2
	buttonVec.push_back(new Button());
	buttonVec.at(1)->setCharacterSize(30);
	buttonVec.at(1)->setString(str2);
	buttonVec.at(1)->setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width * 2 / 4 - buttonVec.at(1)->getGlobalBound().width / 2,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));

	// btn3
	buttonVec.push_back(new Button());
	buttonVec.at(2)->setCharacterSize(30);
	buttonVec.at(2)->setString(str3);
	buttonVec.at(2)->setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width - buttonVec.at(2)->getGlobalBound().width - 35,
		backSpr.getPosition().y + backSpr.getGlobalBounds().height - 80));

}


void Widget::draw(sf::RenderWindow* window)
{
	// draw the background
	window->draw(backgroundRect);

	// message rect
	window->draw(backSpr);

	// message
	window->draw(messageTxt);

	// buttons
	for (Button* btn : buttonVec)
		btn->draw(window);
}

void Widget::onMouseHover()
{
	for (Button* btn : buttonVec)
		if (btn->getGlobalBound().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			btn->onMouseOver();
		}
		else
		{
			btn->setFillColor(sf::Color(220, 220, 220, 240));
		}


}

// message functions
void Widget::setMessageColor(const sf::Color& color)
{
	messageTxt.setFillColor(color);
}
void Widget::setMessageString(const std::string& str)
{
	messageTxt.setString(str);
	messageTxt.setPosition(sf::Vector2f(backSpr.getPosition().x
		+ backSpr.getGlobalBounds().width / 2 - messageTxt.getGlobalBounds().width / 2,
		backSpr.getPosition().y + 50));
}
void Widget::setMessagePosition(const sf::Vector2f& pos)
{
	messageTxt.setPosition(pos);
}
void Widget::setMessageCharacterSize(const us& size)
{
	messageTxt.setCharacterSize(size);
}

bool Widget::isClicked(const sf::Vector2f& pos)
{
	if (backSpr.getGlobalBounds().contains(pos))
		return true;
	else
		return false;
}

void Widget::clicked(const sf::Vector2f& pos, menuType& currentMenu, menuType firstMenu, menuType secondMenu)
{
	if (buttonVec.at(0)->getGlobalBound().contains(pos))
	{
		currentMenu = firstMenu;
	}
	else if (buttonVec.at(0)->getGlobalBound().contains(pos))
	{
		currentMenu = secondMenu;
	}

	activation = false;
}

void Widget::clicked(const sf::Vector2f& pos, menuType& currentMenu, menuType firstMenu, menuType secondMenu, bool& isRestartBtnClicked)
{
	if (buttonVec.at(0)->getGlobalBound().contains(pos))	// firstMenu
	{
		currentMenu = firstMenu;
	}
	else if (buttonVec.at(1)->getGlobalBound().contains(pos))
	{
		currentMenu = secondMenu;
	}
	else if (buttonVec.at(2)->getGlobalBound().contains(pos))
	{
		isRestartBtnClicked = true;
	}

	activation = false;
}

