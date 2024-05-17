#pragma once
#include "player.h"

Player* getPlayer(int level)
{
	static Attr attr;
	if (level == 1)
	{
		attr.maxHealth = attr.health = 300;
		attr.attack = 15;
		attr.defense = 10;

		attr.agility = 5;
		attr.wisdom = 5;
		attr.strength = 5;

		attr.missRate = 5;
		attr.criticalAttackRate = 5;
		attr.attackFirstLevel = 2;
		return new Player(attr, "MyPlayer", 0);
	}
	return nullptr;
}