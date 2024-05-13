#pragma once
#include "monster.h"

Monster getMonster(int level)
{
	if (level == 2) return Monster(50, 15, 7, "Strong Test Monster");
	else if (level == 1) return Monster (20, 5, 5, "Medium Test Monster");
	else return Monster (5, 1, 1, "Weak Test Monster");
	return Monster();
}