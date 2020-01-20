//AlphaMan source

#include "AlphaMan.h"


AlphaMan::AlphaMan(const sf::Vector2i& pos)
{
	heroId = alphaMan;
	damage = 2;
	health = 13;
	//it needs to pushBack itself in a vector

	// hero position in grid
	setHeroPosition(pos);
}


void AlphaMan::attack()
{

}