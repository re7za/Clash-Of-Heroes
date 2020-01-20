
#include "Tile.h"

Tile::Tile()
{
	tileModTex.loadFromFile("Grid/tiles/L0.png");
	tileModSpr.setTexture(tileModTex);
	tileModSpr.getGlobalBounds();
	// set default color : opacity = 0
	tileModSpr.setColor(sf::Color(100, 0, 180, 0));
	tileModOrginalColor = tileModSpr.getColor();
}


void Tile::tileClicked()
{

}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(tileModSpr);
	if (isHeroSpr)
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
bool Tile::IsHeroSpr()
{
	return isHeroSpr;
}
