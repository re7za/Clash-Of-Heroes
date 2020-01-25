#pragma once

#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "../generalDef.h"
#include "Menu.h"
#include "../Grid/Grid.h"
#include "../Button/Button.h"
#include "../Heroes Battle Card/BattleCardManager.h"


class Battlefield : public Menu
{
public:
	Battlefield();
	void display(sf::RenderWindow*);

	////////////////////// mouse events and positions
	void click(sf::Vector2i&, menuType&);

	// utility functions of mouse envents and positions
	void mouseHover(sf::RenderWindow*);
	//////////////////////

	void startTheBattlefield();
	void turnWasChanged(Players);
	void attackProcess();
	

	// background img
	void changeBackground();


private:

	// BattleCardManager
	BattleCardManager battleCardManager;
	
	// battle grid
	Grid grid;

	// button
	Button pauseBtn;



};



#endif