#pragma once

#ifndef generalDef_H
#define generalDef_H

#define us unsigned short 
#define maxHealth 20

#include <string>

enum heros
{
	mrsGhost,
	robi,
	leon,
	drMarry,
	sniper,
	kratos,
	giant,
	alphaMan,
	professor,
	commander,
	rickKhonsari,
	sybil,
	none
};

enum class menuType {
	none,
	mainMenu,
	heroSelection,
	battlefield
};

enum class tileType { L1, L2, L3 };




#endif