#include "Widget.h"

Widget::Widget()
{
	// background rect
	backgroundRect.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width,
		sf::VideoMode::getDesktopMode().height));
	backgroundRect.setPosition(sf::Vector2f(0, 0));
	backgroundRect.setFillColor(sf::Color(0, 0, 0, 25));
	
	// message rect
	messageRect.setSize(sf::Vector2f(700, 300));
	//messageRect.setOrigin(messageRect.getGlobalBounds().width / 2, 0);
	messageRect.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2
		- messageRect.getGlobalBounds().width / 2 , 300));
	messageRect.setFillColor(sf::Color(0, 0, 0, 255));

	// message
	messageFont.loadFromFile("Font/Button.otf");
	messageTxt.setFont(messageFont);
	messageTxt.setFillColor(sf::Color::White);
	messageTxt.setString("your meesage");
	messageTxt.setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width / 2 - messageTxt.getGlobalBounds().width / 2,
		messageRect.getPosition().y + 50));	
}

Widget::Widget(const std::string& str)
	:Widget()
{
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(40);
	buttonVec.at(0)->setString(str);
	buttonVec.at(0)->setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width / 2 - buttonVec.at(0)->getGlobalBound().width / 2,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));
}

Widget::Widget(const std::string& str1, const std::string& str2)
	:Widget()
{
	// btn1
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(40);
	buttonVec.at(0)->setString(str1);
	buttonVec.at(0)->setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width / 3 - buttonVec.at(0)->getGlobalBound().width / 2,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));

	// btn2
	buttonVec.push_back(new Button());
	buttonVec.at(1)->setCharacterSize(40);
	buttonVec.at(1)->setString(str2);
	buttonVec.at(1)->setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width * 2/3 - buttonVec.at(1)->getGlobalBound().width / 2,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));

}

Widget::Widget(const std::string& str1, const std::string& str2, const std::string& str3)
	:Widget()
{
	// btn1
	buttonVec.push_back(new Button());
	buttonVec.at(0)->setCharacterSize(30);
	buttonVec.at(0)->setString(str1);
	buttonVec.at(0)->setPosition(sf::Vector2f(messageRect.getPosition().x + 35,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));

	// btn2
	buttonVec.push_back(new Button());
	buttonVec.at(1)->setCharacterSize(30);
	buttonVec.at(1)->setString(str2);
	buttonVec.at(1)->setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width * 2 / 4 - buttonVec.at(1)->getGlobalBound().width / 2,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));

	// btn3
	buttonVec.push_back(new Button());
	buttonVec.at(2)->setCharacterSize(30);
	buttonVec.at(2)->setString(str3);
	buttonVec.at(2)->setPosition(sf::Vector2f(messageRect.getPosition().x
		+ messageRect.getGlobalBounds().width - buttonVec.at(2)->getGlobalBound().width - 35,
		messageRect.getPosition().y + messageRect.getGlobalBounds().height - 80));

}


void Widget::draw(sf::RenderWindow* window)
{
	// draw the background
	window->draw(backgroundRect);

	// message rect
	window->draw(messageRect);

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
}
void Widget::setMessagePosition(const sf::Vector2f& pos)
{
	messageTxt.setPosition(pos);
}
void Widget::setMessageCharacterSize(const unsigned short& size)
{
	messageTxt.setCharacterSize(size);
}

bool Widget::isClicked(const sf::Vector2f& pos)
{
	if (messageRect.getGlobalBounds().contains(pos))
		return true;
	else
		return false;
}

void Widget::clicked(const sf::Vector2f& pos)
{

}

