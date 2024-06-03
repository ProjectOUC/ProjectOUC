#pragma once
#include "player.h"

Player* getPlayer(int level)
{
	static Attr attr;
	Player* player = nullptr;
	if (level == 1)
		player = new Player("init/basic-warrior.txt");
	else if (level == 2)
		player = new Player("init/basic-rogue.txt");
	return player;
}