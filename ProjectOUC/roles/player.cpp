#pragma once
#include "player.h"

Player* getPlayer(int level)
{
	static Attr attr;
	Player* player = nullptr;
	if (level == 1)
	{
		attr.agility = 5;
		attr.wisdom = 1;
		attr.strength = 10;

		attr.maxHealth = 900;
		attr.health = 1000;
		attr.attack = 1;
		attr.diceNum = 3;
		attr.facet = 8;
		attr.defense = 10;

		attr.hitRate = 5;
		attr.missRate = 5;
		attr.criticalAttackRate = 5;
		attr.attackFirstLevel = 20;

		player = new Player(attr, "Warrior", 100);
		player->set_essentialAttributeType(1);
		player->set_food_capacity(180);
		player->set_food(100);
	}
	else if (level == 2)
	{
		attr.maxHealth = 450;
		attr.health = 500;
		attr.attack = 1;
		attr.diceNum = 5;
		attr.facet = 2;
		attr.defense = 5;

		attr.agility = 8;
		attr.wisdom = 3;
		attr.strength = 5;
		attr.hitRate = 10;
		attr.missRate = 20;
		attr.criticalAttackRate = 8;
		attr.attackFirstLevel = 32;

		player = new Player(attr, "Rogue", 100 + roll(10, 20));
		player->set_essentialAttributeType(2);
		player->set_food_capacity(100);
		player->set_food(100);
	}
	return player;
}