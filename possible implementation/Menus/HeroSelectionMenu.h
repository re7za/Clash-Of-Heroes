#pragma once

#ifndef HEROSELECTIONMENU_H
#define HEROSELECTIONMENU_H

#include "Menu.h"
#include "../Button/Button.h"

class HeroSelectionMenu : public Menu
{
public:
	HeroSelectionMenu();
	void display(sf::RenderWindow*);
	void mouseHover(sf::RenderWindow*);

private:
	Button backBtn;		// مثلا باتن یچیزی از منوعه ولی گرید نه

};


#endif