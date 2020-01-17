
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "HeroSelectionMenu.h"
#include "../Player/PlayerManager.h"
#include "../generalDef.h"
#include <vector>

class MenuManager
{
public:
	MenuManager();
	void displayCurrentMenu(sf::RenderWindow*);
	//static void returnToPreviousMenu();

	menuType getCurrentMenu();
	void setCurrentMenu(menuType);

	// events and positions
	//void getMousePosition(sf::Vector2i);
	void rightClickPos(sf::Vector2i);

private:
	menuType currentMenu;
	std::vector <Menu*> menuVec;
	HeroSelectionMenu heroSelectionMenu;

	// منو منیجر کارش اینه ک منو هارو مدیریت کنه..
	// کلاس منو اتفاقات رو مدیریت میکنه
	// بعضی اتفاقایی ک توی منو میوفته مربوط ب پلیر میشه و بعضیاشم نمیشه
	// پس اینکه جای پلیرمنیجر توی  کلاس منو باشه منطقی تره
	// پس منطقی تر اینه ک پلیر منیجر داخل کلاس منو باشه ن اینجا
};


#endif