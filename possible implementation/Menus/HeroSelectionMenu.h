#pragma once

#ifndef HEROSELECTIONMENU_H
#define HEROSELECTIONMENU_H

#include "Menu.h"
#include "../Button/Button.h"
#include "../Textbox/Textbox.h"
#include <vector>
// heros Card
#include "../Heros Card/HerosCard.h"
#include "../Heros Card/AlphaMan Card.h"
#include "../Heros Card/Commander Card.h"
#include "../Heros Card/DrMarry Card.h"
#include "../Heros Card/Giant Card.h"
#include "../Heros Card/Kratos Card.h"
#include "../Heros Card/Leon Card.h"
#include "../Heros Card/MrsGhost Card.h"
#include "../Heros Card/Professor Card.h"
#include "../Heros Card/RickKhonsari Card.h"
#include "../Heros Card/ROBI Card.h"
#include "../Heros Card/Sniper Card.h"
#include "../Heros Card/Sybil Card.h"

#define nameRectLeft sf::VideoMode::getDesktopMode().width / 2 + 450
#define nameRectHeight 70
#define nameRectWidth 330
#define nameRectTop 220

class HeroSelectionMenu : public Menu
{
public:
	HeroSelectionMenu();
	void display(sf::RenderWindow*);
	void mouseHover(sf::RenderWindow*);
	void drawHerosCard(sf::RenderWindow*);
	void rightClick(sf::Vector2i);
	void rightClickBackBtn(sf::Vector2i);
	void rightClickHeroEachCard(sf::Vector2i);


private:
	Button backBtn;

	// nameBox
	Textbox nameBox;
	sf::RectangleShape nameRect;

	// name input label
	sf::RectangleShape nameInputLabelRect;
	sf::Font nameInputLabelFont;
	sf::Text nameInputLabelText;
	
	// heros Cards
	std::vector<HerosCard*> heroCardVec;
	AlphaManCard alphaManCard;
	CommanderCard commanderCard;
	DrMarryCard drMarryCard;
	GiantCard giantCard;
	KratosCard kratosCard;
	LeonCard leonCard;
	MrsGhostCard mrsGhostCard;
	ProfessorCard professorCard;
	RickKhonsariCard rickKhonsariCard;
	ROBICard ROBICard;
	SniperCard sniperCard;
	SybilCard sybilCard;
};


#endif