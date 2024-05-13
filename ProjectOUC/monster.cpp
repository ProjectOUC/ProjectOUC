#pragma once
#include "monster.h"

Monster getMonster(int level)
{
	static Attr attr;
	if (level == 2) 
	{
		attr.maxHealth = attr.health = 50;
		attr.attack = 15;
		attr.defense = 7;
		attr.attackFirstLevel = 5;
		return Monster(attr, "Strong Test Monster");
	}
	else if (level == 1) 
	{
		attr.maxHealth = attr.health = 20;
		attr.attack = 5;
		attr.defense = 5;
		attr.attackFirstLevel = 3;
		return Monster(attr, "Medium Test Monster");
	}
	else 
	{
		attr.maxHealth = attr.health = 5;
		attr.attack = 1;
		attr.defense = 1;
		attr.attackFirstLevel = 1;
		return Monster(attr, "Weak Test Monster");
	}
}