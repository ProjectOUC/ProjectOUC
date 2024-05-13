#pragma once
#include "chest.h"

Chest getChest(int level)
{
	if (level == 2) return Chest(0, 0, 0, "Large Chest", 100);
	else if (level == 1) return Chest(0, 0, 0, "Medium Chest", 50);
	else if (level == 0) return Chest(0, 0, 0, "Small Chest", 10);
	else return Chest(100, 50, 10, "Chest Monster", 0);
}