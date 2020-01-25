#include "Tile.h"
#include <iostream>

Tile::Tile()
{
	tileModTex.loadFromFile("Grid/tiles/L0.png");
	tileModSpr.setTexture(tileModTex);
	tileModSpr.getGlobalBounds();
	// set default color : opacity = 0
	tileModSpr.setColor(sf::Color(100, 0, 180, 0));
	tileModOrginalColor = tileModSpr.getColor();
}


void Tile::clicked()
{

}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(tileModSpr);
	if (isHeroSpr)
		if (isHeroTex)
			window->draw(*heroSpr);

}

// sfml methodes
void Tile::setFillColor(const sf::Color& color)
{
	tileModSpr.setColor(color);
}
void Tile::setPosition(const sf::Vector2f& position)
{
	tileModSpr.setPosition(position);
}
void Tile::setScale(const sf::Vector2f& scale)
{
	tileModSpr.setScale(scale);
	if (isHeroSpr)
		if (scale.x != 1.2f)
			heroSpr->setScale(scale);
		else
		{
			delete heroSpr;
			switch (currentHero)
			{
			case heros::mrsGhost:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/mrs_ghost icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::robi:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/robi icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::leon:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/leon icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::drMarry:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/dr_marry icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::sniper:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/sniper icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::kratos:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/kratos icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::giant:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/giant icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::alphaMan:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/alpha_man icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::professor:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/professor icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::commander:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/commander icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::rickKhonsari:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/rick_konsari icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			case heros::sybil:
			{
				heroSpr = new sf::Sprite();
				heroTex->loadFromFile("Grid/heroIcon/1.2bigger/sybil icon.png");
				heroSpr->setTexture(*heroTex);
				heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));
				break;
			}
			}
		}
}
sf::FloatRect Tile::getGlobalBound()
{
	return tileModSpr.getGlobalBounds();
}
const sf::Vector2f& Tile::getOrigin()
{
	return tileModSpr.getOrigin();
}
const sf::Vector2f& Tile::getPosition()
{
	return tileModSpr.getPosition();
}
const sf::Vector2f& Tile::getScale()
{
	return tileModSpr.getScale();
}


// set and remove hero and the others
void Tile::setHeroSpr(const heros& heroName)
{
	if (!isHeroSpr)
		switch (heroName)
		{
		case heros::mrsGhost:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/mrs_ghost icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::robi:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/robi icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::leon:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/leon icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::drMarry:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/dr_marry icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::sniper:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/sniper icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::kratos:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/kratos icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::giant:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/giant icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::alphaMan:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/alpha_man icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::professor:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/professor icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::commander:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/commander icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::rickKhonsari:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/rick_konsari icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		case heros::sybil:
		{
			currentHero = heroName;
			heroTex = new sf::Texture();
			heroSpr = new sf::Sprite();
			heroTex->loadFromFile("Grid/heroIcon/sybil icon.png");
			heroSpr->setTexture(*heroTex);
			heroSpr->setPosition(sf::Vector2f(this->getPosition().x + 4, this->getPosition().y + 2));

			isHeroSpr = true;
			isHeroTex = true;
			break;
		}
		}
}
void Tile::removeHeroSpr()
{
	delete heroTex;
	delete heroSpr;
	isHeroSpr = false;
}
void Tile::setHeroTex(bool mood)
{
	isHeroTex = mood;
}
bool Tile::IsHeroSpr()
{
	return isHeroSpr;
}
bool Tile::IsheroTex()
{
	return isHeroTex;
}

heros Tile::getHeroCardName()
{
	return currentHero;
}
