#include "Textbox.h"

Textbox::Textbox()
{
}

Textbox::Textbox(us size, bool sel)
{
	textbox.setCharacterSize(size);
	sf::Font font;
	font.loadFromFile("Font/textbox.ttf");
	textbox.setPosition(0, 0);
	this->setLimit(true, 15);

	textbox.setFont(font);
	isSelected = sel;
	if (sel)
		textbox.setString("_");
	else
		textbox.setString("");

}


void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
		text << static_cast<char> (charTyped);
	else if (charTyped == DELETE_KEY)
		if (text.str().length() > 0)
			deleteLastChar();

	textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";

	for (size_t i = 0; i < t.length(); i++)
		newT += t.at(i);

	text.str("");
	text << newT;

	textbox.setString(text.str());

}

void Textbox::setFont(sf::Font& font)
{
	textbox.setFont(font);
}

void Textbox::setPosition(sf::Vector2f position)
{
	textbox.setPosition(position);
}

void Textbox::setLimit(bool toF)
{
	hasLimit = toF;
}

void Textbox::setLimit(bool toF, int lim)
{
	hasLimit = toF;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";

		for (size_t i = 0; i < t.length(); i++)
			newT += t.at(i);

		textbox.setString(newT);
	}
}

bool Textbox::isItSelected()
{
	return this->isSelected;
}

void Textbox::setFillColor(sf::Color color)
{
	textbox.setFillColor(color);
}

void Textbox::setCharacterSize(us size)
{
	textbox.setCharacterSize(size);
}

void Textbox::setString(const std::string& text)
{
	textbox.setString(text);
}

std::string Textbox::getText()
{
	return text.str();
}

void Textbox::draw(sf::RenderWindow* window)
{
	window->draw(textbox);
}

void Textbox::typedOn(sf::Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
			if (hasLimit)
			{
				if (text.str().length() <= limit)
					inputLogic(charTyped);
				else if (text.str().length() > limit && charTyped == DELETE_KEY)
					deleteLastChar();
			}
			else
				inputLogic(charTyped);
				
	}
}
